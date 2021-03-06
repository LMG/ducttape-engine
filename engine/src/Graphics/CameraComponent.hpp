
// ----------------------------------------------------------------------------
// This file is part of the Ducttape Project (http://ducttape-dev.org) and is
// licensed under the GNU LESSER PUBLIC LICENSE version 3. For the full license
// text, please see the LICENSE file in the root of this project or at
// http://www.gnu.org/licenses/lgpl.html
// ----------------------------------------------------------------------------

#ifndef DUCTTAPE_ENGINE_COMPONENT_CAMERACOMPONENT
#define DUCTTAPE_ENGINE_COMPONENT_CAMERACOMPONENT

#include <Config.hpp>

#include <Scene/Component.hpp>

#include <OgreCamera.h>
#include <OgreVector3.h>

#include <memory>
#include <string>

namespace dt {

/**
  * Adds a camera to the Node.
  */
class DUCTTAPE_API CameraComponent : public Component {
public:
    /**
      * Advanced constructor.
      * @name The name of the component.
      * @see Component
      */
    CameraComponent(const std::string& name = "");

    virtual void HandleEvent(std::shared_ptr<Event> e);

    void OnCreate();
    void OnDestroy();
    void OnUpdate(double time_diff);

    /**
      * Rotates the camera to look at a target point.
      * @param target_point The point to look at.
      */
    void LookAt(Ogre::Vector3 target_point);

    /**
      * Returns the Ogre Camera object.
      * @returns The Ogre Camera object.
      */
	Ogre::Camera* GetCamera();

private:
    Ogre::Camera* mCamera;      //!< The Ogre camera instance.
};

}

#endif
