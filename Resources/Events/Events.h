#pragma once
#define Events_Class_H
#include <vector>
#include <functional>

template<typename Para1>
class Events
{
private:
    std::vector<std::function<void(Para1)>> funcs;

public:
    void AddListener(std::function<void(Para1)> func);
    void Trigger(Para1 data);
};