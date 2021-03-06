CC  = g++
LD	= ld
RM 	= rm
ECHO = /bin/echo
PRINTF	= printf
SED	= sed
CP = cp
MV = mv


PROJECT_ROOT=.
SRCDIR = $(PROJECT_ROOT)
OBJDIR = $(PROJECT_ROOT)/obj

LIBS = -lGL -lGLU -lglut
TARGET = myDraw

SRCS := $(wildcard $(SRCDIR)/*.cpp)
INCS := $(wildcard $(SRCDIR)/*.h)
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

.PHONY: all setup clean distclean

all: setup $(TARGET)

setup:
	@$(ECHO) "Setting up compilation.."
	@mkdir -p obj
	@mkdir -p images

$(TARGET): $(OBJS)
	@$(ECHO) "Building executable..."
	@$(CC) -o $@  $(OBJS) $(LIBS)

-include $(OBJS:.o=.d)

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(PRINTF) "Compiling $(notdir $<)\n"
	@$(CC) $(LIBS) -c $< -o $@

clean:
	@$(ECHO) -n "Cleaning up..."
	@$(RM) -rf $(OBJDIR) *~ $(SRCDIR)/*~
	@$(ECHO) "Done"

distclean:
	@$(ECHO) -n "Cleaning up.."
	@$(RM) -rf $(OBJDIR) *~  $(TARGET)
	@$(ECHO) "Done"
