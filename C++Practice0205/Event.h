#pragma once

#include<memory>
#include<functional>
#include<vector>
#include <algorithm>

class Event
{
public:
    Event()
    {
    };
    Event(const Event&) = delete;
    Event& operator=(const Event&) = delete;

public:

    using FunctionDecl = std::shared_ptr<std::function<void(void)>>;
    using FunctionVector = std::vector<FunctionDecl>;

    template <class Functor>
    void AddFunc(Functor f) {
        m_funcs.emplace_back(FunctionDecl(new std::function<void(void)>(std::move(f))));
    };

    void Run() {
        for (auto& v : m_funcs)
        {
            v->operator()();
        }
    }


private:
    FunctionVector m_funcs;

};