#include <iostream>
#include <cstdint>

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int argc, const char* argv[]) {
    if (!glfwInit()) {
        std::cout << "Hata oluştu >> GLFW'de" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // kullanılan opengl sürümün söylüyor programa
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // kullanılan opengl Min-sürümün söylüyor programa
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //core profili opengl'in modent fonksiyonlarını kullanmaya yarıyor

    GLFWwindow* window = glfwCreateWindow(800, 600, "Sonunda OpenGl =_= Çalıştı", nullptr, nullptr); // opengl in penceresini oluşturuyor 
    if (!window) {//açılmama durumunda hata mesajı verdirecek
        std::cout << "Hata oluştu >> Pencere oluşturulamadı" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);


    




    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { //GLAD kütüphanesi yüklenmez ise kapatıp hata mesajı veriyor
        std::cout << "Hata oluştu >> GLAD yüklenemedi" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

   
    while (!glfwWindowShouldClose(window)) {// açılan pencerenin kendiliğinden kapanmasını engell oluyor
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // arkaplan siyah
        glClear(GL_COLOR_BUFFER_BIT);//back buffere silip yeni rengi uyguluyor

        glfwSwapBuffers(window);
        glfwPollEvents();// pencerenin boyutunun değiştirmesi gibi şeylerin çalışmasına yarıyor
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}