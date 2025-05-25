# Usamos una imagen base de Python
FROM python:3.10-slim

# No guardar archivos .pyc
ENV PYTHONDONTWRITEBYTECODE 1

# Forzar el vaciado del buffer de salida (útil para ver logs en tiempo real)
ENV PYTHONUNBUFFERED 1

# Directorio de trabajo dentro del contenedor
WORKDIR /app

# Copiar y instalar las dependencias
COPY requirements.txt .
RUN pip install --upgrade pip && pip install -r requirements.txt

# Copiar el resto del código de la app
COPY . .

# Comando por defecto para ejecutar Django
CMD ["python", "manage.py", "runserver", "0.0.0.0:8000"]
