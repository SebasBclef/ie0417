# Laboratorio 4: Patrones de diseño en entrevistas técnicas
## 1. Investigación
### Pregunta 1:
“¿Cómo diseñarías un sistema de logging global accesible desde cualquier parte del sistema?”
Fuente: Cracking the Coding Interview

### Pregunta 2:
“Diseña una aplicación que permita intercambiar entre distintos algoritmos de compresión (ZIP, RAR, GZIP, etc.) sin cambiar el cliente.”
Fuente: LeetCode Discussions

### Pregunta 3:
“Supongamos que estás desarrollando una app para múltiples sistemas operativos. ¿Cómo harías que funcione sin acoplarte a una plataforma en particular?”
Fuente: Design Patterns Interview Questions (GitHub)
## 2. Análisis y Aplicación de Patrones
### Pregunta 1:
Entonces, una posible implementación para lograr resolvar la pregunta propuesta, se busca desarrollar una aplicación tenga un acceso a una única instancia del sistema de logging propia del sistema. Entonces, esta instancia se va a poder utilizar en cualquier parte sin crear múltiples objetos.
- Patrón Propuesto: Singleton.
- Justificación: El patrón Singleton garantiza que una clase solo se intancie una vez, y a su vez se proporciona un punto global de acceso. Esto es ideal para el logging, ya que se trabaja con un solo canal centralizado dedicado a escribir logs.
#### Una implementación propuesta sería:
class Logger:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(Logger, cls).__new__(cls)
        return cls._instance

    def log(self, message):
        print(f"[LOG]: {message}")

# Uso
logger1 = Logger()
logger2 = Logger()

logger1.log("Inicio del sistema.")
print(logger1 is logger2)  # True



### Pregunta 2:
Entonces, la implementación va a necesitar utilizar distintos algoritmos de compresión sin que alteren el código del cliente. Sin embargo, los algoritmos sí pueden cambiar dinámicamente.
- Patrón Propuesto: Strategy.
- Justificación: El patrón Strategy permite definir una familia de algoritmos, encapsular cada uno y hacerlos intercambiables. Se utiliza cuando se quiere cambiar el algoritmo en tiempo de ejecución sin modificar el cliente.
#### Una implementación propuesta sería:
class CompressionStrategy:
    def compress(self, data):
        pass

class ZipCompression(CompressionStrategy):
    def compress(self, data):
        print("Usando ZIP para comprimir datos.")

class GzipCompression(CompressionStrategy):
    def compress(self, data):
        print("Usando GZIP para comprimir datos.")

class Compressor:
    def __init__(self, strategy: CompressionStrategy):
        self.strategy = strategy

    def set_strategy(self, strategy: CompressionStrategy):
        self.strategy = strategy

    def compress(self, data):
        self.strategy.compress(data)

# Uso
compressor = Compressor(ZipCompression())
compressor.compress("archivo.txt")

compressor.set_strategy(GzipCompression())
compressor.compress("archivo.txt")


### Pregunta 3:
La app debe funcionar en Windows, Linux y macOS, sin acoplarse a clases específicas de cada sistema operativo.
- Patrón Propuesto: Abstract Factory
- Justificación: Abstract Factory permite crear familias de objetos relacionados sin especificar sus clases concretas. Útil para crear componentes específicos del sistema operativo sin acoplamiento directo.
#### Una implementación propuesta sería:
# Interfaces
class Button:
    def paint(self):
        pass

class WindowsButton(Button):
    def paint(self):
        print("Botón estilo Windows")

class LinuxButton(Button):
    def paint(self):
        print("Botón estilo Linux")

class GUIFactory:
    def create_button(self):
        pass

class WindowsFactory(GUIFactory):
    def create_button(self):
        return WindowsButton()

class LinuxFactory(GUIFactory):
    def create_button(self):
        return LinuxButton()

# Cliente
def build_ui(factory: GUIFactory):
    button = factory.create_button()
    button.paint()

# Uso
os_type = "Linux"
factory = LinuxFactory() if os_type == "Linux" else WindowsFactory()
build_ui(factory)
