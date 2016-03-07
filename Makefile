.PHONY: clean All

All:
	@echo "----------Building project:[ Racional - Debug ]----------"
	@cd "Racional" && "$(MAKE)" -f  "Racional.mk"
clean:
	@echo "----------Cleaning project:[ Racional - Debug ]----------"
	@cd "Racional" && "$(MAKE)" -f  "Racional.mk" clean
