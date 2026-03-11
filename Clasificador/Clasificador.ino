#include "Arduino_LSM9DS1.h"
#include "ArbolGestos.h"

Eloquent::ML::Port::ArbolGestos clasificador;

const int WINDOW_SIZE = 10;

// Arrays acelerómetro
float ax[WINDOW_SIZE], ay[WINDOW_SIZE], az[WINDOW_SIZE];

// Arrays giroscopio
float gx[WINDOW_SIZE], gy[WINDOW_SIZE], gz[WINDOW_SIZE];

void setup() {
  Serial.begin(115200);
  while (!Serial);delay(200);
  IMU.begin();
}

void loop() {

  int muestrasTomadas = 0;

  // ----------- Tomar de las muestras -----------
  while (muestrasTomadas < WINDOW_SIZE) {

    if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {

      float ax_, ay_, az_;
      float gx_, gy_, gz_;

      IMU.readAcceleration(ax_, ay_, az_);
      IMU.readGyroscope(gx_, gy_, gz_);

      ax[muestrasTomadas] = ax_;
      ay[muestrasTomadas] = ay_;
      az[muestrasTomadas] = az_;

      gx[muestrasTomadas] = gx_;
      gy[muestrasTomadas] = gy_;
      gz[muestrasTomadas] = gz_;

      muestrasTomadas++;
    }
  }

 
  float mean_ax = 0;
  float mean_ay = 0;
  float mean_az = 0;

  float mean_gx = 0;
  float mean_gy = 0;
  float mean_gz = 0;
 // ----------- Calcula medias -----------
  for (int i = 0; i < WINDOW_SIZE; i++) {

    mean_ax += ax[i];
    mean_ay += ay[i];
    mean_az += az[i];

    mean_gx += gx[i];
    mean_gy += gy[i];
    mean_gz += gz[i];
  }

  mean_ax /= WINDOW_SIZE;
  mean_ay /= WINDOW_SIZE;
  mean_az /= WINDOW_SIZE;

  mean_gx /= WINDOW_SIZE;
  mean_gy /= WINDOW_SIZE;
  mean_gz /= WINDOW_SIZE;

  // ----------- características -----------
  float features[6] = {
    mean_ax,
    mean_ay,
    mean_az,
    mean_gx,
    mean_gy,
    mean_gz
  };

  // ----------- Clasificación -----------
  int clase = clasificador.predict(features);

  String resultado;

  switch(clase) {

    case 0:
      resultado = "Adelante";
      break;

    case 1:
      resultado = "Atras";
      break;

    case 2:
      resultado = "Izquierda";
      break;

    case 3:
      resultado = "Derecha";
      break;

    case 4:
      resultado = "Quieto";
      break;

    default:
      resultado = "Desconocido";
  }

  // ----------- Mostrar resultado -----------

  Serial.print("Movimiento: ");
  Serial.println(resultado);

  delay(300);
}
