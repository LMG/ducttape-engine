
// ----------------------------------------------------------------------------
// This file is part of the Ducttape Project (http://ducttape-dev.org) and is
// licensed under the GNU LESSER PUBLIC LICENSE version 3. For the full license
// text, please see the LICENSE file in the root of this project or at
// http://www.gnu.org/licenses/lgpl.html
// ----------------------------------------------------------------------------

#include <Core/Root.hpp>

namespace dt {

// This list of new keywords exists to allow us fine-grained control over
// the creation and deletion of these managers.
Root::Root()
    : mLogManager(new LogManager()),
      mStringManager(new StringManager()),
      mEventManager(new EventManager()),
      mResourceManager(new ResourceManager()),
      mInputManager(new InputManager()),
      mDisplayManager(new DisplayManager()),
      mStateManager(new StateManager()),
      mNetworkManager(new NetworkManager()),
      mPhysicsManager(new PhysicsManager()) {}

Root::~Root() {
    // Complementary to the constructor, we destroy the managers in reverse
    // order.
    delete mPhysicsManager;
    delete mNetworkManager;
    delete mStateManager;
    delete mDisplayManager;
    delete mInputManager;
    delete mResourceManager;
    delete mEventManager;
    delete mStringManager;
    delete mLogManager;
}

Root& Root::GetInstance() {
    static Root instance;
    return instance;
}

void Root::Initialize(int argc, char** argv) {
    mSfClock.Reset();

    mExecutablePath = boost::filesystem::system_complete(boost::filesystem::path( argv[0]));

    mLogManager->Initialize();
    mStringManager->Initialize();
    mEventManager->Initialize();
    mResourceManager->Initialize();
    mDisplayManager->Initialize();
    // Do not initialize the InputManager.
    // The display manager does this when the window is created.
    mNetworkManager->Initialize();
    mStateManager->Initialize();
    mPhysicsManager->Initialize();
}

void Root::Deinitialize() {
    mPhysicsManager->Deinitialize();
    mStateManager->Deinitialize();
    mNetworkManager->Deinitialize();
    // Do not deinitialize the InputManager (see above).
    mDisplayManager->Deinitialize();
    mResourceManager->Deinitialize();
    mEventManager->Deinitialize();
    mStringManager->Deinitialize();
    mLogManager->Deinitialize();
}

double Root::GetTimeSinceInitialize() const {
    return mSfClock.GetElapsedTime() / 1000.0;
}

const boost::filesystem::path& Root::GetExecutablePath() const {
    return mExecutablePath;
}

StringManager* Root::GetStringManager() {
    return mStringManager;
}

LogManager* Root::GetLogManager() {
    return mLogManager;
}

StateManager* Root::GetStateManager() {
    return mStateManager;
}

EventManager* Root::GetEventManager() {
    return mEventManager;
}

NetworkManager* Root::GetNetworkManager() {
    return mNetworkManager;
}

DisplayManager* Root::GetDisplayManager() {
    return mDisplayManager;
}

InputManager* Root::GetInputManager() {
    return mInputManager;
}

ResourceManager* Root::GetResourceManager() {
    return mResourceManager;
}

PhysicsManager* Root::GetPhysicsManager() {
    return mPhysicsManager;
}

}
