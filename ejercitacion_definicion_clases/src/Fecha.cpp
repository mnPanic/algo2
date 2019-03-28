//////////////
// PRELUDIO //
//////////////

#include <map>


// Typedef
typedef int Anio;
typedef int Mes;
typedef int Dia;

// MESES
const Mes ENERO = 1;
const Mes FEBRERO = 2;
const Mes MARZO = 3;
const Mes ABRIL = 4;
const Mes MAYO = 5;
const Mes JUNIO = 6;
const Mes JULIO = 7;
const Mes AGOSTO = 8;
const Mes SEPTIEMBRE = 9;
const Mes OCTUBRE = 10;
const Mes NOVIEMBRE = 11;
const Mes DICIEMBRE = 12;

// Ejercicio 1: esBisiesto

bool divisible(int a, int b) {
  return a % b == 0;
}

bool esBisiesto(Anio anio) {
  bool bisiesto =
          divisible(anio, 400) or
          (divisible(anio, 4) and !divisible(anio, 100));

  return bisiesto;
}

// Ejercicio 2: diasEnMes
int diasEnMes(Anio anio, Mes mes) {
  std::map<Mes, Dia> diasPorMes = {
          {ENERO,       31},
          {FEBRERO,     esBisiesto(anio)? 29 : 28},
          {MARZO,       31},
          {ABRIL,       30},
          {MAYO,        31},
          {JUNIO,       30},
          {JULIO,       31},
          {AGOSTO,      31},
          {SEPTIEMBRE,  30},
          {OCTUBRE,     31},
          {NOVIEMBRE,   30},
          {DICIEMBRE,   31},
  };

  return diasPorMes[mes];
}

// Para ejercicio 6
class Periodo;

class Fecha {
 public:
  // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
  Fecha(Anio anio, Mes mes, Dia dia);

  Anio anio() const;
  Mes mes() const;
  Dia dia() const;

  bool operator==(Fecha o) const;
  bool operator<(Fecha o) const;

  // Ejercicio 7: sumar período a fecha

 private:
  Anio _anio;
  Mes _mes;
  Dia _dia;

  // Ejercicio 7: sumar a fecha
  void sumar_anios(int anios);
  void sumar_meses(int meses);
  void sumar_dias(int dias);
};

// Ejercicio 3: Constructor y métodos de Fecha
Fecha::Fecha(Anio anio, Mes mes, Dia dia)
    : _anio(anio), _mes(mes), _dia(dia) {
}

Anio Fecha::anio() const {
    return _anio;
}

// Fecha::mes()
Mes Fecha::mes() const {
    return _mes;
}

// dia
Dia Fecha::dia() const {
    return _dia;
}

// Ejercicio 4: comparadores
bool Fecha::operator==(Fecha o) const {
    bool equal =
        _dia == o._dia and
        _mes == o._mes and
        _anio == o._anio;

    return equal;
}

// Fecha::operator<

bool Fecha::operator<(Fecha o) const {
    bool lt =
        _anio < o._anio or
        ((_anio == o._anio) and
        ((_mes < o._mes) or
         (_mes == o._mes and _dia < o._dia)));

    return lt; // lower than
}


// Ejercicio 5: comparador distinto
bool operator!=(Fecha f1, Fecha f2) {
}

// Ejercicio 6: clase período
class Periodo {
};


// Ejercicio 8: clase Intervalo
