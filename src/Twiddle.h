#ifndef TWIDDLE_H
#define TWIDDLE_H

class Twiddle {
public:
  Twiddle(double tol);
  virtual ~Twiddle();

  // void init(double Kp, double Ki, double Kd);
  bool record(double cte);
  void update();
  double* getBestP();

private:
  bool status = false;
  int count = 0;  // the number of recorders
  int index = 0;  // used to update parameters iteratively
  double tol_;  // used to stop the iterations
  double err_ = 0.0;
  double best_err_;
  double p_[3] = {0.0, 0.0, 0.0};
  double dp_[3] = {1.0, 1.0, 1.0};
  double best_p_[3] = {0.0, 0.0, 0.0};
};

#endif /* TWIDDLE_H */
