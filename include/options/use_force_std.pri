## can be used with Qt 5.12 and later.
## For Qt 5.11 and earlier, it is not a recognized QMake flag and you have to get your hands a bit dirty.
##
## Reference: https://stackoverflow.com/questions/46610996/cant-use-c17-features-using-g-7-2-in-qtcreator

contains(USE_FORCE_STD_17, 1) {
	QMAKE_CXXFLAGS += -std=c++17
}