#include <strata/petri/vects.hpp>
#include <strata/backend/impl.def.hpp>
#include <string>
#include <vector>
enum engine_capabilites {
    enginestats,
    memory_inspect,
    gltf,
    textures,
    models,
    animation,
    video, 
    p2p,
};

enum sys_capabilites {
    mouse  = evs::_MOUSE,
    keyboard  = evs::_KEYBOARD,
    joystick  = evs::_JOY,
    controller  = evs::_CONT,
    INT  = evs::_INT, // Move and acc in games
    audio  = evs::_AUDIO,
    display  = evs::_DISPLAY,
    ui      = evs::_UI,
    sensor  = evs::_SENSOR,
    net = evs::net

};
static const std::map<engine_capabilites,std::string> eng_capabilites_map = {

} ; 

static const std::map< sys_capabilites,std::string > sys_capabilites_map = {
{sys_capabilites::mouse,"STRATA_MOUSE"},
{sys_capabilites::keyboard,"STRATA_KEYBOARD"},
{sys_capabilites::joystick,"STRATA_JOYSTICK"},
{sys_capabilites::controller,"STRATA_CONTROLLER"},
{sys_capabilites::INT,"STRATA_INT"},
{sys_capabilites::audio,"STRATA_AUDIO"},
{sys_capabilites::display,"STRATA_DISPLAY"},
{sys_capabilites::ui, "STRATA_UI"},
{sys_capabilites::sensor,"STRATA_SENSOR"},
{sys_capabilites::net,"STRATA_NET"}
}; 

class capabilities {
    
    std::vector<sys_capabilties> sys_cap;
    std::vector<engine_capabilites> eng_cap;
    public: 
    void push_sys(sys_capabilites sycp){
        for(auto i : this->sys_cap){if(sycp==i){return;};};
        this->sys_cap->push_back(sycp);
    };
    void push_eng(eng_capabilites sycp){
        for(auto i : this->eng_cap){if(sycp==i){return;};};
        this->eng_cap->push_back(sycp);
    };
    bool has_sys_cap(sys_capabilites sycp){for(auto i : this->sys_cap){if(sycp==i){return true;};};};
    bool has_eng_cap(eng_capabilites encp){for(auto i : this->eng_cap){if(encp==i){return true;};};};
    std::string defines(){
        std::string res;res+= "#include <strata/petri/macros.hpp>\ndefmult("+sys_capabilites_map[this->sys_cap[0]];
        for(sys_capabilites t : this->sys_cap}{res+=","+sys_capabilites_map[t];};
         res+= ")\ndefmult("+eng_capabilites_map[this->eng_cap[0]];
        for(eng_capabilites t : this->eng_cap){res+="#define"+eng_capabilites_map[t]+"\n";};
         res+="}";return res
    };
    #define S
    std::string undefines(){
        std::string res;
        for(sys_capabilites t : this->sys_cap}{res+="#undef"+sys_capabilites_map[t]+"\n";};
        for(eng_capabilites t : this->eng_cap){res+="#undef"+eng_capabilites_map[t]+"\n";};
        return res;
    };

    capabilities(std::initializer_list<sys_capabilites> sys_caps,std::initializer_list<engine_capabilites> eng_caps ) :sys_cap(sys_caps) , eng_cap(end_caps){};

};