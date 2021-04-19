# Makefile para el caso 1 de la LIBRERÍA
# ©2021 Inma, Gerardo, Fidel, Juanma, Antonio
#
# --- Parte configurable ---
#
# José Manuel Barba González es el nombre del directorio donde el alumno guarda las
# prácticas de POO (C++). Dentro de ese directorio debe haber uno para
# cada práctica llamado P1, que será de la forma P<n>,
# siendo <n> el número de práctica: P0, P1, etc.

NOMBREALUMNO   = Barba_Gonzalez_JoseManuel
NOMBREPRACTICA = P1

# CADENADIR y FECHADIR son los directorios donde están respectivamente
# los módulos objeto y cabeceras de Cadena y Fecha: cadena.{oh} y fecha.{oh}.
CADENADIR = .
FECHADIR = .
TESTSDIR = ../Tests-auto
#DSL = ../dsl-comprobaciones
# -fexceptions
CXXFLAGS = -g -ansi -pedantic -Wall -std=c++11 -DP1 ${INCLUDES}
# --- Fin parte configurable

INCLUDES  = -I${CADENADIR} -I${FECHADIR} -I${TESTSDIR} #-I${DSL}
LOCALSRC = fecha.cpp cadena.cpp
EXTLIBS   = -lcrypt
LIBS      = ${LOCALSRC} ${EXTLIBS}
VPATH     = .:${CADENADIR}:${FECHADIR}:${TESTSDIR}

COMM_SRCS = $(LOCALSRC)
#MAIN_SRCS = $(COMM_SRCS) test-consola.cpp
MAIN_SRCS = $(COMM_SRCS) test-fechacadena-consola.cpp
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)
#MAIN_EXE  = test-caso4-consola
MAIN_EXE = test-fechacadena-consola
#TEST_SRCS = $(COMM_SRCS) test-auto.cpp
TEST_SRCS = $(COMM_SRCS) test-auto.cpp test-caso0-cadena-auto.cpp test-caso0-fecha-auto.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
#TEST_EXE  = test-p1_4-auto
TEST_EXE  = ../${NOMBREPRACTICA}/test-P1-auto

NOMBRETAR = ../../${NOMBREALUMNO}.tar.gz
NOMBREDIR = ${NOMBREALUMNO}/${NOMBREPRACTICA}

## OBJETIVOS PRINCIPALES #######################################################

.PHONY: all clean dist test-consola test-auto

all: ${MAIN_EXE} ${TEST_EXE}

test-consola: ${MAIN_EXE}
	./$<

test-auto: ${TEST_EXE}
	./$<

clean:
	${RM} ${MAIN_EXE} ${MAIN_OBJS} ${TEST_EXE} ${TEST_OBJS}
	$(RM) *.{aux,log,dvi,toc} *~ \#* *.d *.o

# Esto lo deberían usar los alumnos a la hora de la entrega:
# crea el archivo .tar.gz en el directorio padre tras borrar lo sobrante.
dist: clean ${NOMBRETAR}

## COMPILACIÓN #################################################################

${MAIN_EXE}: ${MAIN_OBJS}
	${CXX} -o $@ ${LDFLAGS} $^ ${EXTLIBS}

${TEST_EXE}: ${TEST_OBJS}
	${CXX} -o $@ ${LDFLAGS} $^ ${EXTLIBS}

# Detección automática de dependencias en código fuente C++ con GCC #

%.d: %.cpp
	@$(CXX) -MM $(CXXFLAGS) $< > $@
	@sed -ri 's,($*)\.o[ :]*,\1.o $@ : ,g' $@

-include $(MAIN_SRCS:.cpp=.d) $(TEST_SRCS:.cpp=.d)

## EMPAQUETADO #################################################################

${NOMBRETAR}:
ifeq ($(strip $(NOMBREALUMNO)),)
	@echo ""
	@echo "ATENCIÓN: debe definir en el Makefile la variable NOMBREALUMNO"
	@echo "con el nombre del directorio superior a este."
	@echo " Vea las instrucciones de entrega de las prácticas."
else
	tar -cvz -C../.. -f ${NOMBRETAR} ${NOMBREDIR}
endif
