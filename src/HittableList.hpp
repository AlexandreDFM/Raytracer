/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** HittableList.hpp
*/

#ifndef HITTABLE_LIST_H
    #define HITTABLE_LIST_H

    #include <memory>
    #include <vector>
    #include "APrimitive.hpp"
    #include "Interface/ILight.hpp"

namespace RayTracer {
    class HittableList : public APrimitive {
        public:
            HittableList() = default;

            HittableList(std::shared_ptr<IPrimitive> object)
            {
                add(object);
            }

            void clear()
            {
                objects.clear();
            }

            void add(std::shared_ptr<IPrimitive> object)
            {
                objects.push_back(object);
            }

            void add(std::shared_ptr<ILight> object)
            {
                lights.push_back(object);
            }

            bool hit(const Ray &r, double tMin, double tMax, hitRecord &rec) const override;

        public:
            std::vector<std::shared_ptr<IPrimitive>> objects;
            std::vector<std::shared_ptr<ILight>> lights;
    };

    inline bool HittableList::hit(const Ray &r, double tMin, double tMax, hitRecord &rec) const {
        hitRecord temp_rec;
        bool hit_anything = false;
        auto closest_so_far = tMax;

        for (const auto &object: objects) {
            if (object->hit(r, tMin, closest_so_far, temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
}

#endif
