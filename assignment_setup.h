#ifndef ASSIGNMENT_SETUP_H
#define ASSIGNMENT_SETUP_H

#include <igl/opengl/glfw/Viewer.h>

igl::opengl::glfw::Viewer viewer;

inline void simulate(double dt, double t) {
}

inline void draw(double t) {
}

inline void assignment_setup(int argc, char **argv) {
    // Inline mesh of a cube
    const Eigen::MatrixXd V = (Eigen::MatrixXd(8, 3) << 0.0, 0.0, 0.0,
                               0.0, 0.0, 1.0,
                               0.0, 1.0, 0.0,
                               0.0, 1.0, 1.0,
                               1.0, 0.0, 0.0,
                               1.0, 0.0, 1.0,
                               1.0, 1.0, 0.0,
                               1.0, 1.0, 1.0)
                                  .finished();
    const Eigen::MatrixXi F = (Eigen::MatrixXi(12, 3) << 1, 7, 5,
                               1, 3, 7,
                               1, 4, 3,
                               1, 2, 4,
                               3, 8, 7,
                               3, 4, 8,
                               5, 7, 8,
                               5, 8, 6,
                               1, 5, 6,
                               1, 6, 2,
                               2, 6, 8,
                               2, 8, 4)
                                  .finished()
                                  .array() -
                              1;

    viewer.data().set_mesh(V, F);
    viewer.data().set_face_based(true);
}

#endif  // ASSIGNMENT_SETUP_H