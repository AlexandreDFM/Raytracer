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
    #include "Interface/IPrimitive.hpp"

namespace RayTracer {
    class HittableList : public IPrimitive {
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

            virtual bool hit(const Ray &r, double t_min, double t_max, hit_record &rec) const override;

        public:
            std::vector<std::shared_ptr<IPrimitive>> objects;
    };

    inline bool HittableList::hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = t_max;

        for (const auto &object: objects) {
            if (object->hit(r, t_min, closest_so_far, temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
}

#endif
