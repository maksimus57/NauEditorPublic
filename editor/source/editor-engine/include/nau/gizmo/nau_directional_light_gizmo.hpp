// Copyright 2024 N-GINN LLC. All rights reserved.
// Use of this source code is governed by a BSD-3 Clause license that can be found in the LICENSE file.
//
// Camera gizmo implementation

#pragma once

#include "nau_gizmo.hpp"

#include <vector>


// ** NauCameraGizmo

class NAU_EDITOR_ENGINE_API NauDirectionalLightGizmo : public NauRotateGizmo {
protected:
    virtual void renderInternal(const nau::math::mat4& transform, int selectedAxes) override;

    //Disable User input for NauDirectionalLightGizmo
    virtual void startUse(nau::math::vec2 screenPoint) {};
    virtual void update(const nau::math::vec3& delta) {};
    virtual void stopUse() {};
};