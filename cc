version: '3.8'

services:
  postgres:
    image: postgres:15
    container_name: notification_postgres
    ports:
      - "5448:5432"
    environment:
      POSTGRES_USER: postgres
      POSTGRES_PASSWORD: admin234
      POSTGRES_DB: notifications
    volumes:
      - pgdata:/var/lib/postgresql/data
      - ./init.sql:/docker-entrypoint-initdb.d/init.sql
    networks:
      - notification_net

  backend:
    build: ./Backend
    container_name: notification_backend
    ports:
      - "3015:3015"
    depends_on:
      - postgres
    networks:
      - notification_net

  frontend:
    build: ./Frontend
    container_name: notification_frontend
    ports:
      - "8030:80"
    depends_on:
      - backend
    networks:
      - notification_net

  hr:
    build: ./HR
    container_name: notification_hr
    ports:
      - "8031:80"
    depends_on:
      - backend
    networks:
      - notification_net

volumes:
  pgdata:

networks:
  notification_net:
    driver: bridge

