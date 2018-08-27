/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef IGNITION_RENDERING_OGRE_OGRENODE_HH_
#define IGNITION_RENDERING_OGRE_OGRENODE_HH_

#include "ignition/rendering/base/BaseNode.hh"
#include "ignition/rendering/ogre/OgreRenderTypes.hh"
#include "ignition/rendering/ogre/OgreObject.hh"

namespace Ogre
{
  class SceneNode;
}

namespace ignition
{
  namespace rendering
  {
    inline namespace IGNITION_RENDERING_VERSION_NAMESPACE {
    //
    class IGNITION_RENDERING_OGRE_VISIBLE OgreNode :
      public BaseNode<OgreObject>
    {
      protected: OgreNode();

      public: virtual ~OgreNode();

      public: virtual bool HasParent() const;

      public: virtual NodePtr Parent() const;

      public: virtual Ogre::SceneNode *Node() const;

      public: virtual void Destroy();

      protected: virtual NodeStorePtr Children() const;

      protected: virtual bool AttachChild(NodePtr _child);

      protected: virtual bool DetachChild(NodePtr _child);

      protected: virtual math::Pose3d RawLocalPose() const;

      protected: virtual void SetRawLocalPose(const math::Pose3d &_Pose3d);

      protected: virtual math::Vector3d RawLocalPosition() const;

      protected: virtual void SetRawLocalPosition(
                     const math::Vector3d &_position);

      protected: virtual math::Quaterniond RawLocalRotation() const;

      protected: virtual void SetRawLocalRotation(
                     const math::Quaterniond &_rotation);

      protected: virtual void SetParent(OgreNodePtr _parent);

      protected: virtual void Load();

      protected: virtual void Init();

      protected: OgreNodePtr parent;

      protected: Ogre::SceneNode *ogreNode = nullptr;

      protected: OgreNodeStorePtr children;

      private: OgreNodePtr SharedThis();

      // TODO(anyone): remove the need for a visual friend class
      private: friend class OgreVisual;
    };
    }
  }
}
#endif
