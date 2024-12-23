FROM gcc:latest
WORKDIR /usr/src/myapp
COPY main.cpp .
RUN gcc -o myapp main.cpp -lstdc++
CMD ["./myapp"]