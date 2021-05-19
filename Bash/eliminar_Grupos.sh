#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con Nombres de grupo a eliminar..."
   exit 1
fi

# Del archivo con el listado de grupos a eliminar:
# Este es el formato:
# ejemplo
#    |   
#    f1  
#$f1 = nombreGrupo

eliminarGrupo(){
	#echo "----> Eliminar Grupo <----"
	eval nombreGrupo="$1"
	#echo "nombreGrupo 		  = ${nombreGrupo}"
	#echo "-------------------------"
	
	#-p, --password PASSWORD
    #Note: This option is not recommended because the password (or encrypted password) will be visible by users listing the processes.
    #You should make sure the password respects the system's password policy.
	#Manejo de error de existencia
	groupdel "${nombreGrupo}"
	if [ $? -eq $SUCCESS ];
        then
		echo "Grupo [${nombreGrupo}] eliminado correctamente..."
        else
		echo "Grupo [${nombreGrupo}] No se pudo eliminar.."
	fi
}

while IFS=: read -r f1
do
	eliminarGrupo "\${f1}"
done < ${file}

