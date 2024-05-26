-- tabla de usuarios
create table if not exists users(
	id int auto_increment primary key,
	username varchar(255) not null,
	password varchar(500) not null,
	email varchar(255) not null,
	surname varchar(255) not null
);
-- tabla de roles
create table if not exists roles(
	id int primary key,
	role_name varchar(50) not null

);
-- tabla intermedia de roles de usuario
create table if not exists users_roles(
	user_id int,
	role_id int,
	foreign key (user_id) references users(id) on delete cascade,
	foreign key (role_id) references roles(id),
	primary key(user_id, role_id)
);
-- tabla sesiones de usuario
create table if not exists user_sessions(
	id int auto_increment primary key,
	user_id int not null,
	token varchar(500) not null,
	created_at timestamp default current_timestamp,
	foreign key (user_id) references users(id) on delete cascade

);
-- intereses academicos/temas
create table if not exists academicTags(
	id int auto_increment primary key,
	tag_name varchar(255) not null
);
-- tabla intermedia intereses academicos
create table if not exists users_academicTags(
	user_id int,
	academicTag_id int,
	foreign key (user_id) references users(id) on delete cascade,
	foreign key (academicTag_id) references academicTags(id),
	primary key(user_id, academicTag_id)

);
-- tabla de grupos de estudio
create table if not exists studyGroups(
	id int auto_increment primary key,
	group_name varchar(255) not null,
	group_owner_id int,
	group_academic_tag int,
	foreign key (group_academic_tag) references academicTags(id),
	foreign key (group_owner_id) references users(id)

);

-- tabla de espacios
create table if not exists espais(
	id int auto_increment primary key,
	name varchar(255) not null,
	proveidor_id int,
	capacity int not null,
	foreign key (proveidor_id) references users(id)

);
-- tabla intermedia para miembros de grupos de estudio
create table if not exists studyGroupsMembership (
    id int auto_increment primary key,
    user_id int,
    group_id int,
    member_since timestamp default current_timestamp,
    foreign key (user_id) references users(id) on delete cascade,
    foreign key (group_id) references studyGroups(id) on delete cascade
);
-- tabla de sesiones de grupo
create table if not exists grupSessions(
	id int auto_increment primary key,
	group_id int,
	espai_id int,
	session_name varchar(255) not null,
	session_start_date timestamp not null,
	session_end_date timestamp not null,
	foreign key (espai_id) references espais(id) on delete cascade,
	foreign key (group_id) references studyGroups(id) on delete cascade
);
-- tabla intermedia para asistentes a sesiones de grupo
create table if not exists grupSessionsAttendants(
	id int auto_increment primary key,
	session_id int,
	user_id int,
	foreign key (session_id) references grupSessions(id) on delete cascade,
	foreign key (user_id) references users(id) on delete cascade
);

create table if not exists notificationType(
	id int auto_increment primary key,
	notification_type varchar(255) not null
);

create table if not exists userNotifications(
	id int auto_increment primary key,
	notification_type int not null,
	status id not null,
	source_grup_id int not null,
	source_user_id int not null,
	destination_user_id int not null,
	foreign key (status) references notificationStatus(id),
	foreign key (source_grup_id) references studyGroups(id),
	foreign key (notification_type) references notificationType(id),
	foreign key (source_user_id) references users(id),
	foreign key (destination_user_id) references users(id)
); 

insert into notificationType(notification_type) values("INVITATION");
insert into notificationType(notification_type) values("REQUEST");


insert into academicTags(tag_name) values("AMEP");
insert into academicTags(tag_name) values("FOMA");
insert into academicTags(tag_name) values("INEP");
insert into academicTags(tag_name) values("PTIN");
insert into academicTags(tag_name) values("ESIN");
-- TODO: completar


-- roles minimos
insert into roles values(1, "ADMIN");
insert into roles values(2, "STUDENT");
insert into roles values(3, "PROVIDER");




