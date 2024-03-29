cmake_minimum_required(VERSION 3.5)
project(juegoDeLaVida)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

include(FindSDL2)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES_TEST
		main.cpp
		solucion.h
		solucion.cpp
		definiciones.h
		tests/esValidoTEST.cpp
		tests/posicionesVivasTEST.cpp
		tests/densidadPoblacionTEST.cpp
		tests/evolucionDePosicionTEST.cpp
		tests/evolucionMultipleTEST.cpp
		tests/evolucionToroideTEST.cpp
		tests/esPeriodicoTEST.cpp
		tests/primosLejanosTEST.cpp
		tests/seleccionNaturalTEST.cpp
		tests/fusionarTEST.cpp
		tests/vistaTrasladadaTEST.cpp
		tests/enCrecimientoTEST.cpp
		tests/nuestros/generales/modTEST.cpp
		tests/nuestros/generales/trasladarTEST.cpp
		tests/nuestros/generales/muertoTest.cpp
		tests/nuestros/generales/mismaDimensionTEST.cpp
		tests/nuestros/seleccionNatural/cantidadDeTicksHastaMorirTEST.cpp
		tests/nuestros/seleccionNatural/noMuereTEST.cpp
		tests/nuestros/esPeriodico/esPeriodicoTEST.cpp
		tests/nuestros/generales/perteneceTEST.cpp
		tests/nuestros/generales/esEstrictamenteEvolucionTEST.cpp
		tests/nuestros/vistaTrasladada/esTraslacionEnDireccionTEST.cpp
		tests/nuestros/enCrecimiento/trasladarToroideTEST.cpp
		tests/nuestros/enCrecimiento/minimaSuperficieQueCubreTEST.cpp
		tests/nuestros/enCrecimiento/obtenerEsquinasQueEncierranPosVivasTEST.cpp
		tests/nuestros/enCrecimiento/columnaTieneAlMenosUnaVivaTEST.cpp
		tests/nuestros/enCrecimiento/filaTieneAlMenosUnaVivaTEST.cpp
		tests/nuestros/enCrecimiento/obtenerDireccionesDeTraslacionTEST.cpp
		tests/nuestros/evolucionToroide/evolucionToroideTEST.cpp
		tests/nuestros/enCrecimiento/enCrecimientoTEST.cpp
		tests/nuestros/enCrecimiento/minimaSuperficieDeTraslacionesQueCubreTEST.cpp
		tests/nuestros/seleccionNatural/seleccionNaturalTEST.cpp
		tests/nuestros/evolucionDePosicion/cantidadVecinosVivosTEST.cpp
		tests/nuestros/evolucionDePosicion/contarCantidadVivasTEST.cpp
		tests/nuestros/evolucionDePosicion/obtenerVecinosTEST.cpp
		tests/nuestros/vistaTrasladada/vistaTrasladadaTEST.cpp
		tests/nuestros/soloBloques/soloBloquesTEST.cpp
		tests/nuestros/primosLejanos/primosLejanosTEST.cpp)

add_executable(juegoDeLaVidaTest ${SOURCE_FILES_TEST})

set_target_properties(juegoDeLaVidaTest PROPERTIES COMPILE_FLAGS "-g --coverage")
set_target_properties(juegoDeLaVidaTest PROPERTIES LINK_FLAGS "-g --coverage")

target_link_libraries(juegoDeLaVidaTest gtest gtest_main)

if(SDL2_FOUND)
	set(SOURCE_FILES_GUI juegoDeLaVida.cpp solucion.h solucion.cpp definiciones.h es.h es.cpp maxiopt.h maxiopt.cpp)
	add_executable(juegoDeLaVida ${SOURCE_FILES_GUI})

	set_target_properties(juegoDeLaVida PROPERTIES COMPILE_FLAGS "-O3")

	target_include_directories(juegoDeLaVida PUBLIC ${SDL2_INCLUDE_DIR})
	target_link_libraries(juegoDeLaVida ${SDL2_LIBRARY})
endif()

set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
