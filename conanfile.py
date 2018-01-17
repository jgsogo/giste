from conans import ConanFile, CMake, tools


class ProtoZooRecipe(ConanFile):
    name = "protozoo"
    version = "0.0.0"
    license = "-- think about it --"
    url = "https://github.com/jgsogo/protozoo.git"
    description = "Generic app framework "
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    generators = "cmake"

    def requirements(self):
        # TODO: Handle this options
        cli = True
        tests = True
        if cli:
            self.requires.add("Boost.Program_Options/1.65.1@bincrafters/stable")
            self.requires.add("Boost.System/1.65.1@bincrafters/stable")
            self.requires.add("Boost.Filesystem/1.65.1@bincrafters/stable")
            self.requires.add("Boost.Dll/1.65.1@bincrafters/stable")
            self.requires.add("yaml-cpp/0.5.3@bincrafters/stable")
            self.requires.add("spdlog/0.14.0@bincrafters/stable")

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

