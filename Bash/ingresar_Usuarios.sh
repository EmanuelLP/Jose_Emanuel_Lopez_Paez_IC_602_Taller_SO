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
   echo "Debe indicar el archivo con el listado de usuarios a ingresar..."
   exit 1
fi

# Del archivo con el listado de usuarios a ingresar:
# Este es el formato:
# ejemplo
#    |
#    f1:f2:f3:f4:f5:f6:f7
#$f1 = username
#$f2 = password (por defecto nombre del usuario)
#$f3 = User ID (no se utiliza si se deja en blanco)
#$f4 = Group ID, debe de existir en /etc/group
#$f5 = User ID Info
#$f6 = home directory
#$f7 = Comand Shell

ingresarUsuario(){
	#se puede realizar tambien con cut -d y asignando que cada : sea la variable
	#echo "----> Ingresar Usuario <----"
	eval user="$1"
	eval password="$2"
	eval userid="$3"
	eval grupoid="$4"
	eval info="$5"
	eval home="$6"
	eval shell="$7"
	#echo "Username 		  = ${user}"
	#echo "-------------------------"

	#Si existe grupoid(f4) se crea el usuario en la direccion /etc/group
	if grep -q ${grupoid} /etc/group
	then
		#echo "GrupoID                     =${grupoid}"
		#echo "Shell                       =${shell}"

		#Se comprueba el nombre(f1) (existe) el usuaruo en /etc/passwd
		if grep -q ${user} /etc/passwd 
		then
			echo "--->Username      existe        =${user}<---"
		else
			#echo "Username     no existe      =${user}"
			#echo "Directorio                  =${home}"
			#Creacion del usaurio con el shell
			#-c comenetario campos GECOS
			#-p contraseña cifrada
			#-d home-dir DIR_PERSONAL 
			#-s sell consola de acceso a la nueva cuenta
			#-u UID identificador de la nueva cuenta 
			#-g identificador de grupo
			useradd -c "${info}" -p "${password}" -d "${home}${user}" -s "${shell}" "${user}"  -g "${grupoid}" 			
			if [ $? -eq $SUCCESS ];
			then
				#echo "Grupo [${nombreGrupo}] agregado correctamente..."
				echo "--->Usuario creado  USER= ${user}   PASSWORD= ${password}<---"
				echo "[${user}:${password}:${userid}:${grupoid}:${info}:${home}${user}:${shell}]"
			else
				echo "Usuario no  creado"
				#echo "Grupo [${nombreGrupo}] No se pudo agregar..."
			fi
			#echo "Usuario creado  USER= ${user}   PASSWORD= ${password}"
		fi
	#echo "Usuario repetido  USER= ${user}   PASSWORD= ${password}"
	else
		echo "No existe el grupo"
		echo "Debe crear grupo  ${grupoid} antes de ingresar el usuario ${user}"
	fi
}

while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do
	#Argumentos de entrada f1:f2:f3:f4:f5:f6:f7
	ingresarUsuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}"
done < ${file}
exit 0
