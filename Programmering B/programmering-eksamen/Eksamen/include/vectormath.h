#ifndef VECTORMATH_H
#define VECTORMATH_H

#define PI (3.14159265358979323846)  /* pi */

namespace math{
    class vector
    {
        public:
            vector(int x, int y);
            virtual ~vector();
            int x, y = 0;
            double length = 0;
            float getSize();
            math::vector makeCross();
            math::vector makeUnit();

        protected:

        private:
    };
}

#endif // VECTORMATH_H
