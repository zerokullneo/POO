.PHONY: clean All

All:
	@echo "----------Building project:[ Polinomio - Debug ]----------"
	@cd "Polinomio" && "$(MAKE)" -f  "Polinomio.mk"
clean:
	@echo "----------Cleaning project:[ Polinomio - Debug ]----------"
	@cd "Polinomio" && "$(MAKE)" -f  "Polinomio.mk" clean
