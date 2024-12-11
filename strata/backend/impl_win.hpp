#include <strata/backend/impl.hpp>
#include <Windows.h>
#ifdef STA_IMPL_VK
#define VK_USE_PLATFORM_WIN32_KHR
#include <vk/vulkan.h>
#endif
#ifdef STA_IMPL_DX
#ifdef D3D12
#include <d3d12.h>
#elifdef D3D11
#include <d3d11.h>
#endif
#include <dxgi.h>
#endif
namespace win_events {
    using events::event;
    using events::event_filter;
    using events::event_main;

    class click : public events::click {
        public:
        click();
    };
    class MOUSE                   :public events::MOUSE                   { 
        virtual void init();
    };         
    class KEY                     :public events::KEY                     {
        virtual void init();
    };
    class JOY                     :public events::JOY                     {
    virtual void init();
    };
    class CONT                  : public events::CONT {

    };
    class TOUCH                   :public events::TOUCH                   { }         
    class INT              :public events::INT            {
    virtual void init();
    }              
    class UI            : public events::UI{

    };
    class DISPLAY   : public events::UI {
        bool gotten;
//         typedef struct _DISPLAY_DEVICEW {
//     DWORD  cb;
//     WCHAR  DeviceName[32];
//     WCHAR  DeviceString[128];
//     DWORD  StateFlags;
//     WCHAR  DeviceID[128];
//     WCHAR  DeviceKey[128];
// } DISPLAY_DEVICEW, *PDISPLAY_DEVICEW, *LPDISPLAY_DEVICEW;
    ivec3 get_display_data(size_t pos=0)final {
        DISPLAY_DEVICE displayDevice;
        displayDevice.cb = sizeof(DISPLAY_DEVICE);
        ivec3 res;
    // Enumerate the monitor by index
        if (EnumDisplayDevices(NULL, monitorIndex, &displayDevice, 0)) {
        DEVMODE devMode;
        devMode.dmSize = sizeof(DEVMODE);
        // Get the current display settings for this monitor
        if (EnumDisplaySettings(displayDevice.DeviceName, ENUM_CURRENT_SETTINGS, &devMode)) {
             res[0] = devMode.dmPelsWidht;
             res[1] = devMode.dmPelsHeight;
             res[2]=devMode.dmDisplayFrequency ; this->disp[pos] = res; return res;
        } else {
            std::cerr << "  Failed to retrieve display settings." << std::endl;
        }
        } else {
        std::cerr << "Monitor index " << monitorIndex << " is invalid." << std::endl;
    }
        
    }
        ivec3 get_monitor_data(size_t pos=0) final {
 MONITORINFOEX monitorInfo;
    monitorInfo.cbSize = sizeof(MONITORINFOEX);

    if (GetMonitorInfo(hMonitor, &monitorInfo)) {
        // Get device context for the monitor
        HDC hdcMonitor = CreateDC(NULL, monitorInfo.szDevice, NULL, NULL);

        // Get physical width and height in millimeters
        int widthMM = GetDeviceCaps(hdcMonitor, HORZSIZE);
        int heightMM = GetDeviceCaps(hdcMonitor, VERTSIZE);
        int hz = GetDeviceCaps(hdcMonitor,VREFRESH);
        return ivec4(widthMM,heightMM);
        DeleteDC(hdcMonitor);
        this->mon[pos] = ivec3(widthMM,heightMM,hz);
        return this->mon[pos];
    };
    else std::cerr<<"Could not get_monitor_data(size_t pos= "<<pos<<")"; 
    delete monitorInfo;
    };
    int get_num_monitors(){
        this->nummon = GetSystemMonitors(SMCMONITORS);
    };
    void get_all(){
        this->get_num_monitors();
        this->disp.clear();
        this->mon.clear();
        for(size_t i =0; i <this->nummon;i++){
            this->get_display_data(i);
            this->get_monitor_data(i);
        };
    };
    
    void _init()final{
        this->get_all();
    // Set callback to new monitor
    };
    };

    }
    class SYS : public events::SYS{
        /*   
using OVERLAPPED= WS_OVERLAPPED; 
using POPUP= WS_POPUP; 
using CHILD= WS_CHILD; 
using MINIMIZE= WS_MINIMIZE; 
using VISIBLE= WS_VISIBLE; 
using DISABLED= WS_DISABLED; 
using CLIPSIBLINGS= WS_CLIPSIBLINGS; 
using CLIPCHILDREN= WS_CLIPCHILDREN; 
using MAXIMIZE= WS_MAXIMIZE; 
using CAPTION= WS_CAPTION; 
using BORDER= WS_BORDER; 
using DLGFRAME= WS_DLGFRAME; 
using VSCROLL= WS_VSCROLL; 
using HSCROLL= WS_HSCROLL; 
using SYSMENU= WS_SYSMENU; 
using THICKFRAME= WS_THICKFRAME; 
using GROUP= WS_GROUP; 
using TABSTOP= WS_TABSTOP; 
using MINIMIZEBOX= WS_MINIMIZEBOX; 
using MAXIMIZEBOX= WS_MAXIMIZEBOX; 
using TILED= WS_TILED; 
using ICONIC= WS_ICONIC; 
using SIZEBOX= WS_SIZEBOX; 
using TILEDWINDOW= WS_TILEDWINDOW; 

 using OVERLAPPEDWINDOW =(OVERLAPPED | CAPTION | SYSMENU | THICKFRAME | MINIMIZEBOX | MAXIMIZEBOX)
 using POPUPWINDOW =(POPUP | BORDER | SYSMENU)
 using CHILDWINDOW =(CHILD)

using DLGMODALFRAME = WS_EX_DLGMODALFRAME ;  
using NOPARENTNOTIFY = WS_EX_NOPARENTNOTIFY ;  
using TOPMOST = WS_EX_TOPMOST ;  
using ACCEPTFILES = WS_EX_ACCEPTFILES ;  
using TRANSPARENT = WS_EX_TRANSPARENT ;  
using MDICHILD = WS_EX_MDICHILD ;  
using TOOLWINDOW = WS_EX_TOOLWINDOW ;  
using WINDOWEDGE = WS_EX_WINDOWEDGE ;  
using CLIENTEDGE = WS_EX_CLIENTEDGE ;  
using CONTEXTHELP = WS_EX_CONTEXTHELP ;  
using RIGHT = WS_EX_RIGHT ;  
using LEFT = WS_EX_LEFT ;  
using RTLREADING = WS_EX_RTLREADING ;  
using LTRREADING = WS_EX_LTRREADING ;  
using LEFTSCROLLBAR = WS_EX_LEFTSCROLLBAR ;  
using RIGHTSCROLLBAR = WS_EX_RIGHTSCROLLBAR ;  
using CONTROLPARENT = WS_EX_CONTROLPARENT ;  
using STATICEDGE = WS_EX_STATICEDGE ;  
using APPWINDOW = WS_EX_APPWINDOW ;  */

    using MIN = strate_env::MIN; 
    using MAX = strate_env::MAX; 
    using HIDE = strate_env::HIDE; 
    using NORMAL = strate_env::NORMAL;
    vect<HWND> wins ;
    vect<ivec4> wind;
    vect<int> state; 
    
    LRESULT void handle_win(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
        if (this->wins[this->cur_win_index]!=hwnd){
            for(int i = 0; i< this->wins.size();i++){if(this->wins[this->cur_win_index]==hwnd){this->cur_win_index=i;break};};
        };
        switch (uMsg) {
        case WM_MOVE: {
            int xPos = LOWORD(lParam); // Horizontal position
            int yPos = HIWORD(lParam); // Vertical position
            this->wind[this->cur_win_index][0]=xPos;
            this->wind[this->cur_win_index][1]=yPos;
            this->move_callback();
            break;
        }
        case WM_RESIZE: {
            int width= LOWORD(lParam);
            int height=HIWORD(lParam);
            this->wind[this->cur_win_index][2]=width;
            this->wind[this->cur_win_index][3]=height;
            this->resize_callback();
        break;
        };
        case WM_MINIMIZE : {this->min_callback();break;};
        case WM_MAXIMIZE : {this->max_callback();break;};
        case WM_RESTORE : {this->restore_callback();break;};
        case WM_HIDE :{this->hide_callback();break;};
        default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
    };
    return 0;
    };
   

    HWND create_win (ivec2 size,ivec2 pos,HWND parent=NULL,bool tool=false,bool custom_tabbar=true, bool resizable=true,bool transparent=false,bool always_on_top=true,char CLASS_NAME[]="DefaultName" ,std::string text=NULL) override {
        // Register class

    WNDCLASS wc = {};
    wc.lpfnWndProc = this->handle_win;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;

    if (!RegisterClass(&wc)) {
        std::cerr << "Failed to register window class!" << std::endl;
        return 1;
    }

        DWORD style = (transparent?WS_EX_TRANSPARENT:0) | (always_on_top?WS_EX_TOPMOST:0)|  (tool?WS_EX_TOOLWINDOW:0) | (custom_tabbar?0:WS_CAPTION) ; 
        HWND winh = CreateWindowEx(
            style,                              // Optional window styles.
            CLASS_NAME,                     // Window class
            text,    // Window text
            WS_OVERLAPPEDWINDOW,            // Window style

            // Size and position
            pox[0]!=0?pos[0]:CW_USEDEFAULT, pos[1]!=0?pos[1]:CW_USEDEFAULT,size[0]!=0?size[1]:CW_USEDEFAULT, size[0]!=0?size[1]:CW_USEDEFAULT,

            parent,       // Parent window    
            NULL,       // Menu
            hInstance,  // Instance handle
            NULL        // Additional application data
        );
        this->wins.push(winh);
        return winh;
    };
    
     ivec2 get_pos(size_t pos){WINDOWPLACEMENT wp={ sizeof(WINDOWPLACEMENT) };GetWindowPlacement(this->wins[pos],&wp);ivec2 s ; s[0] =wp.rcNormalPosition.left;s[1] =wp.rcNormalPosition.top; return s};
     ivec2 get_size(size_t pos){WINDOWPLACEMENT wp={ sizeof(WINDOWPLACEMENT) };GetWindowPlacement(this->wins[pos],&wp);ivec2 s ; s[0] =wp.rcNormalPosition.right-wp.rcNormalPosition.left;s[1] =wp.rcNormalPosition.top -wp.rcNormalPosition.bottom; return s;};
     ivec4 get_data_all(size_t pos){WINDOWPLACEMENT wp={ sizeof(WINDOWPLACEMENT) };GetWindowPlacement(this->wins[pos],&wp);ivec4 s ;s[0] =wp.rcNormalPosition.left;s[1] =wp.rcNormalPosition.top; s[2] =wp.rcNormalPosition.right-wp.rcNormalPosition.left;s[3] =wp.rcNormalPosition.top -wp.rcNormalPosition.bottom;this->wind[pos]=s;return s;};
     void resize_win(size_t pos,ivec2 addpos){ ivec4 s = get_all(); BOOL MoveWindow(this->wins[pos],s[0],s[1],s[2]+addsize[0],s[3]+addsize[1],false); };
     void move_win(size_t pos,ivec2 addsize){ivec4 s = get_all(); BOOL MoveWindow(this->wins[pos],s[0]+addpos[0],s[1]+addpos[1],s[2],s[3],false); };
     void minimize_win(size_t pos)final{ChangeWindowState(this->wind[pos], SW_MINIMIZE);};
     void maximize_win{size_t pos}final{ChangeWindowState(this->wind[pos], SW_MAXIMIZE);};
     void restore_win{size_t pos}final{ChangeWindowState(this->wind[pos], SW_RESTORE);};
     void hide_win(size_t pos)final{ChangeWIndowState(this->wind[pos],SW_HIDE);};

     bool is_min(size_t pos){WINDOWPLACEMENT wp=sizeof(WINDOWPLACEMENT); GetWindowPlacement(w,wp); return (wp.showCmd&(SW_MINIMIZE |SW_SHOWMINIMIZED))?true:false;};
     bool is_hidden(size_t pos){WINDOWPLACEMENT wp=sizeof(WINDOWPLACEMENT); GetWindowPlacement(w,wp); return (wp.showCmd==SW_HIDE)?true:false;};
     bool is_normal(size_t pos){WINDOWPLACEMENT wp=sizeof(WINDOWPLACEMENT); GetWindowPlacement(w,wp); return (wp.showCmd&(SW_RESTORE|SW_SHOW)?true:false;};
     bool is_max(size_t pos){WINDOWPLACEMENT wp=sizeof(WINDOWPLACEMENT); GetWindowPlacement(w,wp); return (wp.showCmd&SW_SHOWMAXIMIZED)?true:false;};
     bool setWindow(HWND w, vec4 pos_w_h, int state){
    WINDOWPLACEMENT wp=sizeof(WINDOWPLACEMENT);
     wp.rcNormaplPosition.left=pos_w_h[0]; wp.rcNormaplPosition.top=pos_w_h[1];
     wp.rcNormaplPosition.right=pos_w_h[2];wp.rcNormaplPosition.bottom=pos_w_h[3];
     wp.showCmd =  ((state&MIN)?SW_SHOWMINIMIZED:0)|((state&MAX)?SW_SHOWMAXIMIZED:0)|((state&HIDDEN)?SW_HIDE:0)|((state&NORMAL)?SW_SHOW:0);
    return  SetWindowPlacement(w,const WINDOWPLACEMENT *wp);
    };
    void close_win(size_t pos){ SendMessage(this->wins[pos], WM_CLOSE, 0, 0);this->wins.erase(pos); if(pos==0) {this->close_app_win_func();};}
    void sleep(int mstime=2000){Sleep(mstime);}
    virtual void _handle(){

    };
    
    virtual void _init(){// Set callbacks
    return;
    }
    

};
};
class win_env : public strata_env<HMODULE,HINSTANCE>{
 
    public:
    
    void init(int flags){

    };
    void initVk(HWND win, VkInstance inst, VKSurfaceKHR* surface, HINSTANCE hInstance=GetModuleHandle(NULL)){ 
        #ifdef STA_IMPL_VK
    VkWin32SurfaceCreateInfoKHR info;
    info.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    info.hinstance = hInstance;
    info.hwnd = win;
         if (vkCreateWin32SurfaceKHR(vkInstance, &info, nullptr, surface) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create Vulkan surface.");
    }
        #endif
    };
     void initDx(){
        #ifdef STA_IMPL_DX
    };

     void load_shared(fs::path p){HMODULE LoadLibrary(p.name(););};
    
    template <typename func>
    func get_func(const char* funcname; HMODULE m){return (func)GetProcAddress(m,name); };
    void unload_shared(HMODULE m){FreeLibrary(m);};
};