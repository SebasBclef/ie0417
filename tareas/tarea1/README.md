# Tarea 1: Modelos Ágiles y Herramientas de Gestión de Proyectos en la Industria del Software. Sebastián Bonilla Vega, C01263.
## Herramientas de gestión de proyectos de software y tecnología de apoyo:
Existen diversas y variadas tecnologías y herramientas que se pueden utilizar con el objetivo de gestionar proyectos. Dichos proyectos abarcan varias áreas, que no se ven limitadas exclusivamente al área de desarrollo de software, lo que vuelve estas metodologías universales. Por consiguiente, la versatilidad de estás herramientas amerita y vuelve atractiva su aprendizaje profundo y sensato. Para empezar, se van a analizar las herramientas de **Jira, Trello y Azure DevOps**:

### Jira
Jira es una herramienta desarrollada por la empresa Atlassian, lanzada el 2002. Su principal uso consiste en la gestión de proyectos de software, con énfasis particular para equipos que quieran desarrollar sus proyectos a través de metodologías ágiles. Algunas de sus funcionalidades principales incluyen:
 - Tableros de metodologías Kanban y Scrum.
 - Seguimientos de incidencias y errores a través de informes detallados sobre el rendimiento del equipo.
 - Permite integración con herramientas como Confluence, Bitbucket, y , más relevante, Github, ya que es la plataforma principal en la que se va a desarrollar todo el curso.

Jira se relaciona con metodologías ágiles a través de Scrum y Kanban, como se vió en los puntos anteriormente. Scrum permite la creación de sprints, backlog y asignación de tareas, promoviendo así la eficiencia e independencia en el desarrollo de proyectos, sin dejar ir el plan de tareas a seguir. Por otro lado, Kanban permite facilitar la visualización del flujo de trabajo, mediante tableros que logran ser personalizables. Entonces, al juntar ambas metodologías, se logra visualizar el progreso que realiza cada uno de los colaboradores, a través de los sprints. Se puede acceder a la página oficial de Jira [aquí.](https://www.atlassian.com/software/jira?campaign=18442480203&adgroup=140479881486&targetid=kwd-855725830&matchtype=e&network=g&device=c&device_model=&creative=656562805651&keyword=jira&placement=&target=&ds_eid=700000001558501&ds_e1=GOOGLE&gad_source=1&gclid=CjwKCAjwwLO_BhB2EiwAx2e-34B7j6vK0XZa13Rj52wgB0VfWpg2jBOJh8zZUNwtLBwLTtcev296oxoCOJcQAvD_BwE)

###  Trello
Trello, al igual que Jira, es una herramienta desarrollada por Atlassian, liberada en el 2011. Sin embargo, a diferencia de Jira, Trello se enfoca más en lo visual. Particularmente, hace uso de tableros visuales y de tarjetas para así lograr una ogranización de tareas llamativa, eficiente y concisa. Sus principales funcionalidades abarcan:
- Interfaces intuitivas basadas en arrastrar y soltar, como click and drag.
- Tableros, listas y tarjetas personalizables.
- Integración con aplicaciones como Slack  y Google Drive.

Trello también se relaciona con las metodologías ágiles de Scrum y Kanban. Kanban, al ser tan visual y al estar tan enfocado en organización llamativa, es la integración natural a ésta herramienta. Sin embargo, Scrum también tiene sus ventajas para esta herramienta. Esto es más que todo debido a que, si bien no hay soporte nativo y literal para los sprints, la gestión de backlog que brinda la metodología Scrum es perfecta para el uso de Trello.Se puede acceder a la página oficial de Trello [aquí.](https://trello.com/es)

### Azure Devops
Azure Devops, a diferencia de las otras 2 tecnologías, fué desarrollado por Microsoft para la gestión de proyectos con integración directa para CI/CD. Algunas funcionalidades brindadas por Azure incluyen:
- Seguimiento de tareas individuales y sprints de Scrum.
- Repositorios de código realizados con git.
- Pipelines dedicados a la integración y despliegue continuo.
Se puede accesar a la página oficial de Azure Devops [aquí.](https://azure.microsoft.com/es-es/products/devops)


Ahora, habiendo visto un poco de las metodologías escogidas, se puede hacer la siguiente tabla, resaltando los atributos más relevantes primero:

| Herramienta    | Facilidad de uso | Integración | Popularidad |
|---------------|----------------|------------|-------------|
| Jira         | Media          | Alta       | Alta        |
| Trello       | Alta           | Media      | Alta        |
| Azure DevOps | Media          | Alta       | Media       |

## Marco Teórico Profundo de Scrum y Kanban
### Historia y Origen de Cada Enfoque
#### Scrum
Scrum fue formalmente introducido en 1995. Fue desarrollado por **Jeff Sutherland y Ken Schwaber**, en la coferencia de OOPSLA del mismo año (Object Oriented Programming, Systems, Languages and Applications). Su origen principal se basa en un archivo escrito en 1986 por Takeuchi y Nonaka, donde se compara el desarrollo de productos con un 'Scrum' de Rugby. Entonces, la popularidad de Scrum crece con la moda del movimiento ágil.
#### Kanban
Kanban, en contraste, tiene sus raíces mucho más engranadas y antiguas. Taiichi Ohnoo desarrolló este enfoque como un método para mejorar la eficiencia productiva en Toyota durante la década de 1940. Sin embargo, volvió a reaparecer en la década de los 2000, cuando **David J. Anderson** adaptó la metodología Kanban para el desarrollo y diseño de Software.
### Principios Fundamentales
#### Scrum
- Transparencia: Todos los procesos y progresos del desarrollo de software deben ser visibles y trazables por todo el equipo de trabajo.
- Inspección: Cualquier avance realizado o logrado debe ser inspeccionado y revisado de manera regular y consistente.
- Adaptación: Los procesos deben ser ajustados y realimentados en función del feedback recibido y desarrollado. 
#### Kanban
- Visualización de Trabajo: Se usan tableros fisicos para representar todas las tareas y las subdivisiones de las mismas.
- Limitación del Trabajo en Proceso (WIP): Esto se hace con el objetivo de evitar la sobrecarga hacia el equipo desarrollador.
- Gestión del Flujo: La metodología visual de Kanban permite visualizar y optimizar las entregas de los proyectos y trabajos. 
-Mejora Continua:Se pueden implementar cambios graduales y lentos para lograr optimizar el sistema en desarrollo.
### Estructura de Trabajo
#### Scrum
- Roles: Product Owner, Scrum Master y Equipo de Desarrollo.
- Artefactos: Product Backlog, Sprint Backlog y el Incremento.
- Ceremenias Scrum: Sprint Planning, Daily Scrum, Sprint Reviwe y Sprint Retrospective.
#### Kanban
- Columnas: Representan los estados del trabajo (To Do, In Progress y Done.)
- Flujo de Trabajo: Control del avance de las tareas en el tablero.
- WIP (Work In Progress): Corresponde al límite de tareas en cada estado.
### Ventajas y Desventajas
| Aspecto       | Scrum                                                              | Kanban                                         |
|---------------|--------------------------------------------------------------------|------------------------------------------------|
| Flexibilidad  | Menos flexible por los sprints definidos                           | Adaptable a cambios inmediatos                 | 
| Roles         | Estructura clara con roles definidos                               | No hay roles específicos                       | 
| Entrega       | Incremental con entregas al final de cada sprint                   | Flujo continuo de entregas                     | 
| Adaptabilidad | Pejor para proyectos con requisitos bien definidos y estructurados | Sirve para proyectos con requisitos fluctuantes| 
### Entonces...¿Cuándo Usar Uno u Otro?
- Scrum resulta ser más util en proyectos planificbales, donde se necesiten entregas incrementales, de poco a poco. Entonces, donde sea que se requiera una estructura más definida, es preferible escoger scrum.
- Kanban resulta ser mejor para situaciones en las que los equipos manejen tareas en flujo continuo,  como soporte técnico o mantenimiento.