FROM node:18

WORKDIR /app

COPY package*.json ./
RUN npm install
COPY . .

# Install wait-port globally
RUN npm install -g wait-port

EXPOSE 3015

# Wait for Postgres to be ready, then start server
CMD wait-port postgres:5432 && node server.js

