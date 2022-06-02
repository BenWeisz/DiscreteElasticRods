#include <Eigen/Dense>

#include "assignment_setup.h"

double dt = 0.001;
double t = 0.0;

bool simulating = true;

extern igl::opengl::glfw::Viewer viewer;

bool simulation_callback() {
    while (simulating) {
        simulate(dt, t);
        t += dt;
    }

    return false;
}

bool draw_callback(igl::opengl::glfw::Viewer &viewer) {
    draw(t);
    return false;
}

int main(int argc, char *argv[]) {
    // Set up the model
    assignment_setup(argc, argv);

    // Run the simulation on a separate thread
    std::thread simulation_thread(simulation_callback);
    simulation_thread.detach();

    // Visualize Everything
    viewer.callback_post_draw = &draw_callback;
    viewer.launch();
}
