from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class morecmathRecipe(ConanFile):
    name = "morecmath"
    version = "0.1"
    package_type = "library"

    # Optional metadata
    license = "GPL-3"
    author = "wardenscove wardenscove@gmail.com"
    url = "https://github.io/conan-io/conan-center-index"
    description = "Math library with extra useful functions"
    topics = ("math", "useful", "vector")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def layout(self):
        cmake_layout(self)
    
    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.set_property("cmake_find_mode", "both")
        self.cpp_info.set_property("cmake_file_name", "MORECMATH")
        self.cpp_info.set_property("cmake_target_name", "MORECMATH::MORECMATH")
        self.cpp_info.set_property("pkg_config_name", "morecmath")

        if self.settings.os == "Windows" and self.settings.get_safe("compiler_runtime"):
            libname = "mcmll" if self.options.shared else "zlib"
        else:
            libname = "mcm"

        self.cpp_info.libs = ["morecmath"]

