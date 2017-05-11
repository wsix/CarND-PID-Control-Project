#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  Kp = 0.0;
  Ki = 0.0;
  Kd = 0.0;
  prev_cte = 0.0;
  is_prev_cte_inited = false;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  prev_cte = 0.0;
  is_prev_cte_inited = false;
}

void PID::UpdateError(double cte) {
  if (!is_prev_cte_inited) {
    prev_cte = cte;
    is_prev_cte_inited = true;
  }

  p_error = cte;
  i_error += cte;
  d_error = cte - prev_cte;

  prev_cte = cte;
}

double PID::TotalError() {
  return -Kp * p_error - Ki * i_error - Kd * d_error;
}
