from conan import ConanFile
from conan.tools.cmake import cmake_layout

class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("gstreamer/1.24.7")

    def layout(self):
        cmake_layout(self)
