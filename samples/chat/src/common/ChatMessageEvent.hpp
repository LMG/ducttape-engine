
// ----------------------------------------------------------------------------
// This file is part of the Ducttape Project (http://ducttape-dev.org) and is
// licensed under the GNU LESSER PUBLIC LICENSE version 3. For the full license
// text, please see the LICENSE file in the root of this project or at
// http://www.gnu.org/licenses/lgpl.html
// ----------------------------------------------------------------------------

#ifndef DUCTTAPE_SAMPLE_CHAT_COMMON_CHATMESSAGEEVENT
#define DUCTTAPE_SAMPLE_CHAT_COMMON_CHATMESSAGEEVENT

#include <Network/NetworkEvent.hpp>

class ChatMessageEvent : public dt::NetworkEvent {
public:
    ChatMessageEvent(const std::string& message, const std::string& sender);
    const std::string GetType() const;

    std::shared_ptr<dt::Event> Clone() const;
    void Serialize(dt::IOPacket& p);

    const std::string& GetMessageEvent() const;
    const std::string& GetSenderNick() const;
protected:
    std::string mMessage;
    std::string mSenderNick;
};

#endif
