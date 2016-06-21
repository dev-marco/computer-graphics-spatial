#ifndef MODULE_SPATIAL_INTERSECTION_H_
#define MODULE_SPATIAL_INTERSECTION_H_

#include "vec.h"
#include "defaults.h"

namespace Spatial {

    namespace Intersection {

        Vec<3> __default_vec_3_;
        float_max_t __default_float_max_;
        unsigned __default_unsigned_;
        bool __default_bool_;

        namespace Point {

            bool Point (
                const Vec<3> &point_1,
                const Vec<3> &point_2,
                Vec<3> &closest_point = __default_vec_3_
            );

            bool Line (
                const Vec<3> &point,
                const Vec<3> &line_point,
                const Vec<3> &line_delta,
                Vec<3> &closest_point = __default_vec_3_,
                float_max_t &t_inter = __default_float_max_
            );

            bool Plane (
                const Vec<3> &point,
                const Vec<3> &plane_normal,
                const Vec<3> &plane_point,
                Vec<3> &closest_point = __default_vec_3_
            );
        };

        namespace Line {

            // NOTE Real-Time Collision Detection
            bool Line (
                const Vec<3> &line_1_point,
                const Vec<3> &line_1_delta,
                const Vec<3> &line_2_point,
                const Vec<3> &line_2_delta,
                float_max_t &t_1,
                float_max_t &t_2
            );

            // NOTE Real-Time Collision Detection : 176
            bool Plane (
                const Vec<3> &line_point,
                const Vec<3> &line_delta,
                const Vec<3> &plane_normal,
                const Vec<3> &plane_d,
                float_max_t &t_inter = __default_float_max_
            );

            // NOTE Real-Time Collision Detection : 178
            bool Sphere (
                const Vec<3> &line_point,
                const Vec<3> &line_delta,
                const Vec<3> &sphere_center,
                const float_max_t &sphere_radius,
                float_max_t &t_min = __default_float_max_,
                float_max_t &t_max = __default_float_max_
            );

            // NOTE Real-Time Collision Detection : 180
            bool Box (
                const Vec<3> &line_point,
                const Vec<3> &line_delta,
                const Vec<3> &box_min,
                const Vec<3> &box_max,
                float_max_t &t_min = __default_float_max_,
                float_max_t &t_max = __default_float_max_
            );

            // NOTE Real-Time Collision Detection : 197
            bool Cylinder (
                const Vec<3> &line_point,
                const Vec<3> &line_delta,
                const Vec<3> &cylinder_top,
                const Vec<3> &cylinder_bottom,
                const float_max_t &cylinder_radius,
                float_max_t &t_min = __default_float_max_,
                float_max_t &t_max = __default_float_max_,
                bool &is_cap_min = __default_bool_,
                bool &is_cap_max = __default_bool_
            );

            // NOTE Real-Time Collision Detection : 199
            bool Polyhedron (
                const Vec<3> &line_point,
                const Vec<3> &line_delta,
                const std::vector<std::pair<Vec<3>, Vec<3>>> &planes,
                float_max_t &t_min = __default_float_max_,
                float_max_t &t_max = __default_float_max_,
                unsigned &face_min = __default_unsigned_,
                unsigned &face_max = __default_unsigned_
            );
        };
    };
};

#endif
