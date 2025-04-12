## Sebastián Bonilla Vega, C01263.
Además, el laboratorio se hizo en conjunto con:
- Brenda Castro Jiménez, C21904.
- Luis Brenes Castro, C21324.
- Byron Arguedas López, C10606.
---

# Escenario: Sistema de inscripción a cursos universitarios

---

# Requerimientos Funcionales

## Autenticación de Usuario

El sistema debe permitir que el usuario se autentique mediante un **nombre de usuario** y una **contraseña**.

### Requisitos del Nombre de Usuario

- Debe tener una **longitud mínima de 3 caracteres**.
- Solo puede contener **letras y números**.

### Requisitos de la Contraseña

- La **longitud mínima** debe ser de **8 caracteres**.
- Debe contener **al menos un carácter especial** (por ejemplo: `*`, `-`, `_`, `+`, etc.).
- **No puede contener el nombre de usuario** en ningún formato (mayúsculas, minúsculas o combinaciones).
- **No debe tener más de 2 caracteres repetidos consecutivos**.


## Interfaz de Usuario

El sistema debe disponer de **tres ventanas o pantallas principales**, cada una con funcionalidades específicas:

### Ventana de Información Personal

- Muestra los **datos personales del estudiante** (nombre, número de identificación, dirección de correo, etc.).
- Permite **editar los datos personales**, excepto el nombre y el número de identificación.
- Incluye un **botón para actualizar la información**.
- Permite la **visualización del historial de cambios realizados** en la información personal (última fecha de modificación).

### Ventana de Cursos Matriculados

- Muestra una lista de los cursos en los que el estudiante está **matriculado actualmente**.
- Para cada curso, se debe mostrar:
  - Nombre del curso
  - Nombre del profesor
  - Número de créditos
  - Horario
  - Aula
- Indica el **estado de la matrícula**: activo, en espera o cancelado.
- Los **cursos ya aprobados** deben mostrar una **estrella** junto al nombre, incluyendo la **calificación obtenida**.
- Ofrece la opción de **retirar cursos** si el estudiante aún no ha asistido a la primera clase.

### Ventana de Cursos Disponibles

- Muestra todos los cursos que están disponibles para matrícula en el semestre.
- Permite **filtrar los cursos** por:
  - Carrera
  - Ciclo
  - Horario
- Indica si un curso tiene **requisitos previos** (con un enlace a los cursos correspondientes).
- Muestra:
  - Nombre del curso
  - Créditos
  - Horario
- El estudiante puede **seleccionar un curso** para ver más detalles, incluyendo:
  - Profesor asignado
  - Cantidad de vacantes disponibles


## Visualización del Plan de Estudios

El sistema debe permitir al estudiante ver el **plan de estudios** de cada carrera disponible.

### Distribución por Ciclos

- Los cursos deben estar organizados por **ciclo** (semestre, trimestre, etc.).
- Para cada ciclo se debe mostrar:
  - Nombre de los cursos
  - Créditos por curso
  - Total de créditos del ciclo
- Si un curso es **requisito de otro**, debe indicarse con un **enlace o nota**.

### Créditos Totales

- El sistema debe mostrar el **total de créditos** que el estudiante debe completar para cada carrera.

### Cursos Aprobados

- Los cursos **aprobados** deben marcarse con una **estrella**, dentro de la cual aparecerá la **calificación obtenida**.

### Plan de Estudio Completo

- El estudiante podrá visualizar todos los **planes de estudio disponibles** para las carreras ofrecidas.
- Podrá **elegir cuál consultar**.
- El sistema debe proporcionar detalles adicionales sobre los **requisitos de cada carrera**, como:
  - Duración del programa
  - Materias optativas

## Matriculación de Cursos

- El sistema debe permitir al estudiante **seleccionar un curso** de la lista de cursos disponibles y **proceder con la matrícula**.
- Una vez matriculado, el curso debe aparecer en la lista de **cursos matriculados** con su respectiva información.
- Los cursos matriculados deben **actualizarse automáticamente en tiempo real** y reflejarse en la ventana correspondiente.

## Generación de Informe de Matrícula

El sistema debe generar un **informe detallado** de la matrícula del estudiante, incluyendo:

- Nombre completo del estudiante
- Número de identificación del estudiante
- Nombre de la universidad
- Fecha de generación del informe
- Créditos de cada curso matriculado
- Horario de cada curso
- Créditos totales de los cursos matriculados
- Aula en la que se impartirán las lecciones
- Nombre del curso
- Profesor encargado del curso
- Duración total del curso
- Semestre o ciclo en el que se cursa
- Detalles adicionales sobre los requisitos previos de los cursos (si los hubiera)

> El informe debe ser **exportable a formato PDF o similar** para su **descarga e impresión**.

---

# Requerimientos No Funcionales

### Tiempo de Respuesta

- El sistema debe responder a las **solicitudes de autenticación de usuario** en un tiempo máximo de **1 nanosegundo**.

### Generación de Reportes

- El sistema debe generar el **reporte de matrícula** en un tiempo máximo de **5 microsegundos**.

### Despliegue del Plan de Estudios

- El sistema debe desplegar el **plan de estudios** en un tiempo máximo de **10 microsegundos**.

### Capacidad de Procesamiento

- El sistema debe ser capaz de **procesar un millón de peticiones simultáneas** sin afectar su rendimiento.

---

# Requerimiento Técnico

## Base de Datos Relacional

El sistema debe utilizar una **base de datos relacional SQL** para almacenar todos los datos relacionados con el usuario, los cursos, la matrícula y otros elementos necesarios para la operación del sistema.

### Estructura de la Base de Datos

La base de datos debe estar diseñada para garantizar la **integridad y consistencia** de los datos, utilizando **claves primarias** y **foráneas** para establecer relaciones entre las tablas (por ejemplo, entre estudiantes y cursos).

Las tablas clave deben incluir:

#### Usuarios

- Contendrá los **datos personales** del estudiante, como:
  - Nombre
  - Correo electrónico
  - Número de identificación
  - Detalles de autenticación (nombre de usuario, contraseña)

#### Cursos

- Incluirá la información relacionada con los **cursos ofrecidos**, como:
  - Nombre del curso
  - Créditos
  - Requisitos previos
  - Horarios
  - Aula
  - Profesor asignado

#### Matrícula

- Esta tabla gestionará las relaciones entre **estudiantes y cursos**, guardando información sobre:
  - Los cursos en los que se ha matriculado cada estudiante
  - La fecha de matrícula
  - El estado del curso (aprobado, pendiente, cancelado)

#### Plan de Estudios

- Contendrá la **estructura del plan de estudios** de cada carrera, especificando:
  - Los ciclos
  - Los cursos asociados a cada ciclo
  - Créditos correspondientes
  - Requisitos de los cursos

## Consultas y Reportes

- La base de datos debe soportar **consultas complejas** para la generación de reportes, como el informe de matrícula del estudiante.
- Debe permitir **búsquedas eficientes** entre los cursos, estudiantes y planes de estudio.
- Las consultas deben ejecutarse de manera rápida, incluso cuando se manejan grandes cantidades de datos (por ejemplo, **1 millón de registros de matrícula**).

## Escalabilidad y Mantenimiento

- El sistema debe estar diseñado de manera que sea **fácilmente escalable**, permitiendo la adición de más registros a medida que la universidad crezca y se amplíen las ofertas de cursos.
- Debe implementarse un sistema de **respaldos automáticos** para prevenir la pérdida de datos críticos y asegurar la continuidad del servicio.
- El sistema debe permitir el **mantenimiento sencillo** de los datos, como:
  - Actualizaciones de curso
  - Cambios en horarios y profesores
  - Eliminación de registros obsoletos
- Todo esto debe realizarse sin comprometer el rendimiento.

## Seguridad

- La base de datos debe estar protegida con **mecanismos de autenticación y autorización** para garantizar que solo los usuarios con permisos adecuados puedan acceder a los datos sensibles, como la **información personal del estudiante** o el **historial académico**.
- La información de las **contraseñas de los usuarios** debe ser almacenada de forma segura utilizando técnicas de **cifrado**, como **hash** y **salting**, para evitar que los datos sean comprometidos en caso de un ataque.

---

# Caso de Uso: Matricular un Curso

## Actor principal
- **Estudiante**

## Interesados y Objetivos

- **Estudiante:** Quiere acceder al sistema y matricular un curso disponible.
- **Universidad:** Necesita verificar que el estudiante es legítimo y registrar correctamente la matrícula.

## Precondiciones
- El estudiante debe tener una **cuenta activa** en el sistema con su **usuario y contraseña**.
- El sistema debe estar **operativo** y con capacidad para recibir peticiones.

## Poscondiciones
- El **curso seleccionado** se añade correctamente a la lista de **cursos matriculados** del estudiante.
- El estudiante puede ver el curso en la **ventana de "Cursos Matriculados"**.
- El sistema debe **generar un informe de matrícula** con los detalles del curso recién matriculado.

## Flujo Principal

1. El estudiante ingresa al **sitio web** del sistema de inscripción.
2. El estudiante introduce su **nombre de usuario y contraseña**.
3. El estudiante hace clic en el **botón Entrar** para iniciar sesión.
4. El sistema verifica las **credenciales** del estudiante.
5. El estudiante es redirigido a la **ventana de Cursos Disponibles**.
6. El estudiante **navega** por la lista de cursos disponibles.
7. El estudiante **selecciona el curso** que desea matricular.
8. El estudiante hace clic en el **botón Matricular**.
9. El sistema solicita al estudiante que **ingrese su contraseña nuevamente** para confirmar la acción.
10. El estudiante **ingresa la contraseña** y hace clic en **Confirmar**.
11. El sistema **verifica** la contraseña para asegurar la autenticidad de la acción.
12. Si la contraseña es correcta, el sistema **registra al estudiante** en el curso seleccionado.
13. El curso se añade a la lista de **Cursos Matriculados** del estudiante y se **genera un informe** con los detalles de la matrícula (nombre del curso, créditos, profesor, etc.).
14. El estudiante recibe un **mensaje de confirmación** de matrícula exitosa.

## Flujos Alternativos

### Flujo Alternativo 1: Contraseña incorrecta

- Si la contraseña ingresada en el paso 9 es incorrecta:
  1. El sistema muestra un **mensaje de error** indicando que la contraseña es incorrecta.
  2. El estudiante tiene la opción de **ingresar nuevamente la contraseña** o **cancelar** la acción.
  3. Si el estudiante opta por **cancelar**, se redirige a la **ventana de Cursos Disponibles** sin completar la matrícula.
  4. Si la contraseña es corregida, el flujo continúa desde el paso 9.

### Flujo Alternativo 2: El estudiante no tiene cursos disponibles

- Si el estudiante accede a la **ventana de Cursos Disponibles** y no encuentra cursos disponibles para matricularse:
  1. El sistema muestra un **mensaje** indicando que no hay cursos disponibles en ese momento.
  2. El estudiante puede optar por **revisar su Plan de Estudios** o **Consultar Información Personal**.
  3. El flujo se redirige a la ventana de **Plan de Estudios** o **Cursos Matriculados**.

### Flujo Alternativo 3: Generación de informe

- Después de matricular el curso, el sistema **genera automáticamente** un informe de matrícula detallado con los cursos en los que el estudiante está matriculado, créditos, horarios, y más.
- El estudiante tiene la opción de **descargar o imprimir** el informe en formato PDF.

---

# Caso de Uso: Ver Plan de Estudios

## Actor principal
- **Estudiante**

## Interesados y Objetivos

- **Estudiante:** Quiere consultar el **plan de estudios** de la carrera o los cursos disponibles para su carrera.
- **Universidad:** Necesita ofrecer una manera eficiente para que el estudiante pueda ver la **distribución de los cursos** y los **requisitos** para su carrera.

## Precondiciones
- El estudiante debe tener una **cuenta activa** en el sistema con su **usuario y contraseña**.
- El sistema debe estar **operativo** y con capacidad para recibir peticiones.
- El estudiante debe estar matriculado en una carrera.

## Poscondiciones
- El estudiante puede **ver el plan de estudios** de su carrera o cualquier carrera disponible.
- El estudiante puede **navegar** entre los diferentes ciclos y visualizar los cursos correspondientes a cada uno.
- El estudiante puede ver los **créditos de cada curso** y los **requisitos previos** para cada uno de ellos.

## Flujo Principal

1. El estudiante inicia sesión en el **sistema** con su nombre de usuario y contraseña.
2. El sistema verifica las **credenciales** del estudiante.
3. El estudiante es redirigido a la **pantalla principal**.
4. El estudiante selecciona la opción de **Ver Plan de Estudios** desde el menú.
5. El sistema muestra una lista de las **carreras disponibles** o la carrera en la que el estudiante está matriculado.
6. El estudiante selecciona su **carrera** para ver el plan de estudios correspondiente.
7. El sistema muestra la **distribución de los cursos** por ciclo, indicando:
   - Nombre de los cursos.
   - Créditos de cada curso.
   - Requisitos previos de los cursos (si existen).
   - El total de créditos para completar la carrera.
8. El estudiante puede navegar entre los **diferentes ciclos** (semestres o trimestres) para ver los cursos correspondientes a cada ciclo.
9. El sistema permite **expandir** la información de cada curso, mostrando detalles como:
   - El profesor asignado.
   - Horario del curso.
   - Aula en la que se imparte.
   - Requisitos previos (si los hay).
10. El estudiante tiene la opción de **volver a la pantalla principal** o consultar más detalles sobre otros cursos de la carrera.

## Flujos Alternativos

### Flujo Alternativo 1: Carrera no disponible

- Si el estudiante no tiene una carrera asignada o la carrera seleccionada no está disponible:
  1. El sistema muestra un **mensaje de error** indicando que no hay información disponible para esa carrera.
  2. El estudiante puede optar por **revisar otras carreras disponibles** o consultar su **información personal**.

### Flujo Alternativo 2: Error en la carga del plan de estudios

- Si el sistema no puede cargar la información del plan de estudios debido a un **error técnico**:
  1. El sistema muestra un **mensaje de error** indicando que no se puede cargar el plan de estudios en ese momento.
  2. El estudiante tiene la opción de **intentar nuevamente** o volver a la **pantalla principal**.

### Flujo Alternativo 3: Información adicional de curso

- Si el estudiante selecciona un curso y desea obtener más detalles:
  1. El sistema muestra la **descripción completa** del curso, incluyendo:
     - Objetivos del curso.
     - Requisitos previos detallados.
     - Duración del curso.
  2. El estudiante puede **cerrar la ventana** de detalles y continuar visualizando el plan de estudios o seleccionar otro curso.

# Diagrama final:
![Captura de pantalla](diagrama.png)
