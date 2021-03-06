#ifndef MODULE_GRAPHICS_GEOMETRY_LINE_H_
#define MODULE_GRAPHICS_GEOMETRY_LINE_H_

#include "defaults.h"
#include "vec.h"

namespace Geometry {
    class Line {

        Vec<3> point, direction;

    public:
        Line () {}

        Line (const Vec<3> &_point, const Vec<3> &_direction) :
            point(_point), direction(_direction.normalized()) {}

        inline const Vec<3> &getPoint (void) const { return this->point; }
        inline const Vec<3> &getDirection (void) const { return this->direction; }

        inline void setPoint (const Vec<3> &_point) { this->point = _point; }
        inline void setDirection (const Vec<3> &_direction) { this->direction = _direction.normalized(); }

        inline Vec<3> at (float_max_t param) const { return this->getPoint() + (this->getDirection() * param); }
        float_max_t param (const Vec<3> &point) const;

        inline Line perpendicular (void) const { return Line(this->getPoint(), this->getDirection().perpendicular()); }
    };
};

#endif
