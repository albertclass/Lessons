O = obj

!ifdef DEBUG
OUTDIR 	= Debug
!else
OUTDIR 	= Release
!endif

OBJDIR	= Obj\$(OUTDIR)

!ifdef DEBUG
CFLAGS       = -Zi -DPDCDEBUG -MDd -D_CRT_SECURE_NO_WARNINGS
LDFLAGS      = -debug -pdb:$(OUTDIR)\out.pdb
!else
CFLAGS       = -Ox -MD -W3 -D_CRT_SECURE_NO_WARNINGS
LDFLAGS      =
!endif

CCLIBS      = user32.lib gdi32.lib advapi32.lib shell32.lib comdlg32.lib
BUILD      	= $(CC) -Fo$(OBJDIR)\ -Fd$(OBJDIR)\ -I$(SRCDIR) -c $(CFLAGS) 

all: $(L01) $(L02) $(L03)

clean:
   -rmdir /s /q $(OUTDIR)
   -rmdir /s /q $(OBJDIR)

L01: "01 c++ type\main.cpp"