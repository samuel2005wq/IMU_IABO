#pragma once


namespace Eloquent {
    namespace ML {
        namespace Port {
            class ArbolGestos {
                public:
                    /**
                    * Predice la clase para un vector de 6 caracteristicas:
                    * x[0]=Accel_X  x[1]=Accel_Y  x[2]=Accel_Z
                    * x[3]=Gyro_X   x[4]=Gyro_Y   x[5]=Gyro_Z
                    */
                    int predict(float *x) {
                        if (x[0] <= -0.2840999960899353) {
                            if (x[5] <= -54.913299560546875) {
                                return 3;
                            }
                            else {
                                return 1;
                            }
                        }
                        else {
                            if (x[4] <= 74.26459884643555) {
                                if (x[5] <= 4.098549842834473) {
                                    if (x[5] <= -6.570349931716919) {
                                        if (x[4] <= 21.832200050354004) {
                                            if (x[5] <= -13.116499900817871) {
                                                return 3;
                                            }
                                            else {
                                                if (x[4] <= 7.2571001052856445) {
                                                    return 3;
                                                }
                                                else {
                                                    return 0;
                                                }
                                            }
                                        }
                                        else {
                                            if (x[5] <= -52.64590072631836) {
                                                return 3;
                                            }
                                            else {
                                                return 0;
                                            }
                                        }
                                    }
                                    else {
                                        if (x[0] <= 0.016950000543147326) {
                                            if (x[1] <= 0.1757499948143959) {
                                                if (x[2] <= 0.9880000054836273) {
                                                    if (x[0] <= -0.0986500009894371) {
                                                        if (x[3] <= 1.2574000358581543) {
                                                            return 3;
                                                        }
                                                        else {
                                                            return 1;
                                                        }
                                                    }
                                                    else {
                                                        if (x[4] <= -9.527649760246277) {
                                                            return 0;
                                                        }
                                                        else {
                                                            if (x[0] <= -0.04344999976456165) {
                                                                if (x[1] <= 0.0820000022649765) {
                                                                    return 3;
                                                                }
                                                                else {
                                                                    if (x[0] <= -0.04449999891221523) {
                                                                        return 4;
                                                                    }
                                                                    else {
                                                                        return 2;
                                                                    }
                                                                }
                                                            }
                                                            else {
                                                                return 4;
                                                            }
                                                        }
                                                    }
                                                }
                                                else {
                                                    if (x[3] <= 0.35384999960660934) {
                                                        return 2;
                                                    }
                                                    else {
                                                        return 4;
                                                    }
                                                }
                                            }
                                            else {
                                                if (x[0] <= -0.06974999979138374) {
                                                    if (x[2] <= 0.9483000040054321) {
                                                        return 2;
                                                    }
                                                    else {
                                                        if (x[4] <= -9.173499822616577) {
                                                            return 0;
                                                        }
                                                        else {
                                                            return 4;
                                                        }
                                                    }
                                                }
                                                else {
                                                    return 3;
                                                }
                                            }
                                        }
                                        else {
                                            if (x[0] <= 0.03580000065267086) {
                                                return 3;
                                            }
                                            else {
                                                if (x[4] <= -3.0548499822616577) {
                                                    return 2;
                                                }
                                                else {
                                                    return 0;
                                                }
                                            }
                                        }
                                    }
                                }
                                else {
                                    if (x[4] <= -9.905900239944458) {
                                        if (x[3] <= 3.7016499787569046) {
                                            return 0;
                                        }
                                        else {
                                            return 1;
                                        }
                                    }
                                    else {
                                        if (x[0] <= 0.14294999837875366) {
                                            if (x[5] <= 4.785300016403198) {
                                                if (x[0] <= -0.028250000439584255) {
                                                    return 2;
                                                }
                                                else {
                                                    return 4;
                                                }
                                            }
                                            else {
                                                return 2;
                                            }
                                        }
                                        else {
                                            return 0;
                                        }
                                    }
                                }
                            }
                            else {
                                if (x[5] <= 75.5890007019043) {
                                    return 0;
                                }
                                else {
                                    return 2;
                                }
                            }
                        }
                    }

                protected:
            };
        }
    }
}
