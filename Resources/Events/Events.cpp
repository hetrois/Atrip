#include "Events.h"

template<typename Para1>
void Events<Para1>::AddListener(std::function<void(Para1)> func)
{
    funcs.push_back(func);
}

template<typename Para1>
void Events<Para1>::Trigger(Para1 data)
{
    for (auto& func : funcs)
    {
        func(data);
    }
}