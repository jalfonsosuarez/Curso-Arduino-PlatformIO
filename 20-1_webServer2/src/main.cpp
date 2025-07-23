#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#define LED 2

const char *ssid = "Aula 1";
const char *pwd = "Horus.2025";

String ledStatus = "off"; // estado del led

String homePage = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Document</title></head><body><h1>Hola mundo</h1><h2>Esta es la página home</h2><hr><a href=\"/firstPage\">Ir a la primera página.</a></body></html>";
String firstPage = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Document</title></head><body><h2>Esta es la primera página</h2><hr></body></html>";

WiFiServer server(80);
// WebServer server(80);

// --------------
void homePage();
void pageOne();
// --------------

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n");
  Serial.print("Conectado a: ");
  Serial.println(WiFi.localIP());

  // server.on("/", homePage);
  // server.on("/firstPage", firstPage);

  server.begin(); // Inicia el servidor
  Serial.println("Servidor iniciado");
}

void loop()
{
  WiFiClient client = server.available(); // Recibe las conexiones de clientes

  if (client)
  {                                   // Si hay un cliente
    Serial.println("Nuevo cliente."); // Indica el acceso de un cliente
    String currentLine = "";          // Variable para datos de fin de linea
    while (client.connected())
    { // Cliente conectado
      if (client.available())
      {                            // Datos disponibles para ser leido
        char byte = client.read(); // Lectura de byte en variable C
        Serial.write(byte);        // Muestra los datos

        if (byte == '\n')
        { // Si el byte es un caracter de nueva linea

          if (currentLine.length() == 0)
          { // Si no hay caracteres, entonces lanza el codgo HTML
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");

            client.println("<style>html{font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button {border: none;color: white;padding: 15px 32px; text-align: center;");
            client.println("text-decoration: none;display: inline-block;font-size: 16px; margin: 4px 2px;cursor: pointer;}");
            client.println(".button1 {background-color: #4CAF50;} /* Green */");
            client.println(".button2 {background-color: #008CBA;} /* Blue */");
            client.println("</style></head>");

            // Creación de botones
            client.print("<body><h1>WebServer con ESP32</h1>");

            if (ledStatus == "off")
            {
              client.println("<button type='button' class='button button1' onClick=location.href='/LED=ON'> ENCENDER </button><br><br>");
            }
            else
            {
              client.println("<button type='button' class='button button2' onClick=location.href='/LED=OFF'> APAGAR </button><br><br>");
            }

            client.print("</body></html>");
            client.println();

            // Rompe el codigo del while-loop
            break;
          }
          else
          { // Limpiando variable
            currentLine = "";
          }
        }
        else if (byte != '\r')
        {                      // Si no hay retorno de carro
          currentLine += byte; // agrega al final de la linea
        }

        // Revisando el datos recibido del url
        if (currentLine.indexOf("GET /LED=ON") != -1)
        {
          digitalWrite(LED, HIGH); // GET /LED=ON
          ledStatus = "on";
        }
        if (currentLine.indexOf("GET /LED=OFF") != -1)
        {
          digitalWrite(LED, LOW); // GET /LED=OFF
          ledStatus = "off";
        }
      }
    }
    // cerrando la conexión
    client.stop();
    Serial.println("Cliente Desconectado");
  }
}

void homePage()
{
  // server.send(200, "text/html", homePage);
}

void pageOne()
{
  // server.send(200, "text/html", firstPage);
}
