double l = 0;
double r = 0;
double g = 0;
double b = 0;
int photocell;
void setup ()
{
  Serial.begin(9600);
  pinMode (7, INPUT_PULLUP);
  pinMode (9, OUTPUT);  //red
  pinMode (10, OUTPUT); //green
  pinMode (11, OUTPUT); //blue
}
void loop (){
  if (digitalRead(7) == HIGH){
    {
      for (l = 400; l < 700; l++){
        double t;  r=0.0; g=0.0; b=0.0;
         if ((l>=400.0)&&(l<410.0)) { t=(l-400.0)/(410.0-400.0); r=    +(0.33*t)-(0.20*t*t); }
    else if ((l>=410.0)&&(l<475.0)) { t=(l-410.0)/(475.0-410.0); r=0.14         -(0.13*t*t); }
    else if ((l>=545.0)&&(l<595.0)) { t=(l-545.0)/(595.0-545.0); r=    +(1.98*t)-(     t*t); }
    else if ((l>=595.0)&&(l<650.0)) { t=(l-595.0)/(650.0-595.0); r=0.98+(0.06*t)-(0.40*t*t); }
    else if ((l>=650.0)&&(l<700.0)) { t=(l-650.0)/(700.0-650.0); r=0.65-(0.84*t)+(0.20*t*t); }
         if ((l>=415.0)&&(l<475.0)) { t=(l-415.0)/(475.0-415.0); g=             +(0.80*t*t); }
    else if ((l>=475.0)&&(l<590.0)) { t=(l-475.0)/(590.0-475.0); g=0.8 +(0.76*t)-(0.80*t*t); }
    else if ((l>=585.0)&&(l<639.0)) { t=(l-585.0)/(639.0-585.0); g=0.84-(0.84*t)           ; }
         if ((l>=400.0)&&(l<475.0)) { t=(l-400.0)/(475.0-400.0); b=    +(2.20*t)-(1.50*t*t); }
    else if ((l>=475.0)&&(l<560.0)) { t=(l-475.0)/(560.0-475.0); b=0.7 -(     t)+(0.30*t*t); }
    r=r*220;
    g=g*220;
    b=b*220;
        analogWrite(9, r);
        analogWrite(10, g);
        analogWrite(11, b);
        delay(50);
        photocell = analogRead(0);
        Serial.print(l);
        Serial.print(",");
        Serial.println(photocell);
        delay(50);
      }
        analogWrite(9, 0);
        analogWrite(10, 0);
        analogWrite(11, 0);
    }
  }
}
