GHC:=ghc -O2 -cpp				\
	-DBOOM_LIMIT=255

files_in=$(wildcard gen/*.hs)
files_bin=$(patsubst gen/%.hs,gen/%.bin,$(files_in))
files_out=$(patsubst gen/%.hs,%.ixx,$(files_in))

all: $(files_out) all.ixx

.PHONY: clean
clean:
	rm -f $(files_bin) $(files_out)

gen/%.bin: gen/%.hs
	$(GHC) $< -o $(patsubst %.hs,%.bin,$<)

%.ixx: gen/%.bin
	./$< > $@

all.ixx: gen/all.bin $(filter-out all.ixx,$(files_out))
	./gen/all.bin $(filter-out $@,$(files_out)) > $@
