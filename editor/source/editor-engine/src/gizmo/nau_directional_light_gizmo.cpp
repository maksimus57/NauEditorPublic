// Copyright 2024 N-GINN LLC. All rights reserved.
// Use of this source code is governed by a BSD-3 Clause license that can be
// found in the LICENSE file.

#include "nau/gizmo/nau_directional_light_gizmo.hpp"
#include "nau/debugRenderer/debug_render_system.h"
#include "nau/editor-engine/nau_editor_engine_services.hpp"
#include "nau/scene/components/directional_light_component.h"
#include "nau/viewport/nau_viewport_utils.hpp"

#include <QMouseEvent>
#include <QPoint>

static const nau::math::E3DCOLOR ColorYellow = {255, 255, 0};

void NauDirectionalLightGizmo::renderInternal(const nau::math::mat4& basis,
                                              int selectedAxes)
{
    using namespace nau::math;
    //NauRotateGizmo::renderInternal(basis, selectedAxes);

    auto& dr = nau::getDebugRenderer();

    mat4 rot = mat4::identity().rotationY(std::numbers::pi / 2);
    dr.drawArrow(
            Point3(basis.getCol3().getXYZ()),
            Point3(basis.getCol3().getXYZ()) +
            normalize(basis * f3Tov3(nau::scene::DirectionalLightComponent::FORWARD)) * m_axesLength3d * 2,
            ColorYellow, basis.getCol1().getXYZ(), 1);
}

