<?PHP
	session_start();
	if (file_exists("../private/user.json"))
	{
		$database = file_get_contents("../private/user.json");
		$old_data = json_decode($database, true);
		foreach ($old_data['user'] as $login)
		{
			if (($_POST['login'] == $login['user']['login']) OR (!$_POST['passwd']) OR (!$_POST['login']))
			{
				echo "ERREUR!\nVEUILLEZ REMPLIR LE FORMULAIRE.";
				return;
			}
		}
	}
	$user_info = array();
	$user_info['login'] = $_POST['login'];
	$user_info['passwd'] = hash("whirlpool", $_POST['passwd']);
	$user_data = $old_data;
	$user_data['user'] = $user_info;
   	$new_data['user'][] = json_encode($user_data);
	file_put_contents("../private/user.json", $new_data);
	echo "COMPTE ENREGISTRE\n";
?>
