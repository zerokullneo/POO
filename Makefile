.PHONY: clean All

All:
	@echo "----------Building project:[ fexterna - Debug ]----------"
	@cd "fexterna" && "$(MAKE)" -f  "fexterna.mk"
clean:
	@echo "----------Cleaning project:[ fexterna - Debug ]----------"
	@cd "fexterna" && "$(MAKE)" -f  "fexterna.mk" clean
