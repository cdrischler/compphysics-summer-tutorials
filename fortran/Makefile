FC=gfortran
SRCS=exp-good.f90 exp-bad.f90
BUILDS=$(patsubst %.f90,%.a,$(SRCS))
FFLAGS=-O3

all: $(BUILDS)

%.a: %.f90
	$(FC) $(FFLAGS) $< -o $@

clean:
	@rm -f $(BUILDS) *.out
