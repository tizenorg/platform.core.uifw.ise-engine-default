#sbs-git:slp/pkgs/i/ise-engine-default ise-engine-default 0.1.4911 f634a59ecb8104768dec809386789faac1a3c121
Name:       ise-engine-default
Summary:    Multilingual Keyboard ISE
Version:    0.1.5023
Release:    1
Group:      TO_BE/FILLED_IN
License:    TO_BE/FILLED_IN
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  pkgconfig(isf)

%description
Multilingual Keyboard Input Service Engine (ISE) is a keyboard input method (IM), and
it is based on Input Service Framework(ISF).

%prep
%setup -q

%build

./bootstrap
%configure --prefix=%{_prefix} --disable-static

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install


%files
%defattr(-,root,root,-)
/usr/lib/scim-1.0/1.4.0/IMEngine/ise-engine-default.so
/usr/share/scim/icons/isf-default.png
