#include <gtest/gtest.h>

#include "mpc/system/continuous_system.hpp"

using namespace mpc::system;

class OneDimCart : public ContinuousSystem<2, 1> {
   public:
    void dynamics(const State &state, const Control &control,
                   const Time &time, State &result) const override {
        const auto &pos = state(0);
        const auto &vel = state(1);
        const auto &acc = control(0);
        result(0) = vel;
        result(1) = acc;
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
    system.dynamics(state, control, time, result);
    expected(0) = state(1);
    expected(1) = control(0);

    ASSERT_EQ(result, expected);
}