// See the file "COPYING" in the main distribution directory for copyright.

#include "VLAN.h"
#include "plugin/Plugin.h"
#include "packet_analysis/Component.h"

namespace zeek::plugin::Zeek_VLAN {

class Plugin : public zeek::plugin::Plugin {
public:
    zeek::plugin::Configuration Configure()
        {
        AddComponent(new zeek::packet_analysis::Component("VLAN",
                         zeek::packet_analysis::VLAN::VLANAnalyzer::Instantiate));

        zeek::plugin::Configuration config;
        config.name = "Zeek::VLAN";
        config.description = "VLAN packet analyzer";
        return config;
        }

} plugin;

}
