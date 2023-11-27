#include <gtest/gtest.h>

#include "mpc/system/continuous_system.hpp"

using namespace mpc::system;

class OneDimCart : public ContinuousSystem<2, 1> {
   public:
    State dynamics(const State &state, const Control &control,
                   const Time &time) const override {
        State result;
        const auto &pos = state(0);
        const auto &vel = state(1);
        const auto &acc = control(0);
        result << vel, acc;
        return result;
    }
};

TEST(System, ContinuousSystemInit) {
    OneDimCart system;
    OneDimCart::State state;
    OneDimCart::Control control;
    OneDimCart::Time time;

    state << 0.0, 0.0;
    control << 1.0;
    time = 0.0;

    OneDimCart::State result, expected;
    result = system.dynamics(state, control, time);
    expected << state(1), control(0);

    ASSERT_EQ(result, expected);
}