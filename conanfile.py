from conans import ConanFile, CMake, tools


class GisteRecipe(ConanFile):
    name = "Giste"
    version = "0.0.0"
    license = "-- think about it --"
    url = "https://github.com/jgsogo/giste.git"
    description = "Application/framework to work with corpus (PLN)"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    generators = "cmake"

    def requirements(self):
        self.requires.add("Boost/1.64.0@conan/stable")

    def source(self):
        pass

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include", src="hello")
        # self.copy("*hello.lib", dst="lib", keep_path=False)
        # self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["hello"]

