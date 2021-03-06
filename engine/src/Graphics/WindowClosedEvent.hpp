
// ----------------------------------------------------------------------------
// This file is part of the Ducttape Project (http://ducttape-dev.org) and is
// licensed under the GNU LESSER PUBLIC LICENSE version 3. For the full license
// text, please see the LICENSE file in the root of this project or at
// http://www.gnu.org/licenses/lgpl.html
// ----------------------------------------------------------------------------

#ifndef DUCTTAPE_ENGINE_EVENT_WINDOWCLOSEDEVENT
#define DUCTTAPE_ENGINE_EVENT_WINDOWCLOSEDEVENT

#include <Config.hpp>

#include <Event/Event.hpp>

#include <memory>
#include <string>

namespace dt {

/**
 * Event being sent when sending a pause toggle to the music.
 */
class DUCTTAPE_API WindowClosedEvent : public Event {
public:
    /**
     * Default constructor.
     */
    WindowClosedEvent();
    const std::string GetType() const;
    std::shared_ptr<Event> Clone() const;
};

}

#endif
